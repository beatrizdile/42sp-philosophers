/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:45:57 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 17:52:01 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *routine(void *philo)
{
	get_data()->is_anyone_dead = 2;
	pthread_mutex_lock(&get_data()->print);
	usleep(1000 * 500);
	printf("%lums", get_time() - get_data()->start_time);
	pthread_mutex_unlock(&get_data()->print);
	// while(/*alguem morreu && ja comeu tudo*/)
	// {
		// philo_eat(); 
		// philo_think();
		philo_sleep(((t_philo *)philo)->id);
	// }
	return (NULL);
}

void init_threads(void)
{
	pthread_t	 	*pthread;
	const t_data	*data = get_data();
	int				i;

	pthread = ft_calloc(data->num_of_philos, sizeof(pthread_t));
	i = -1;
	while (++i < data->num_of_philos)
		pthread_create(&pthread[i], NULL, &routine, (void *)&data->philos[i]);
	i = -1;
	while (++i < data->num_of_philos)
		pthread_join(pthread[i], NULL);
	free(pthread);
}

int main(int argc, char **argv)
{
	int	flag;

	flag = check_args(argc, argv);
	if (flag == 1)
		one_philo();
	else if (flag == 2)
	{
		set_data(argc, argv);
		init_threads();
		free_for_finish(get_data());
	}
	return (0);
}

// dps de pensar: come, dps de comer: dorme, dps de dormir: pensa