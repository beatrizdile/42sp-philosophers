/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:45:57 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/16 14:13:41 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *philo)
{
	// ja comeu o suficiente?
	while(!(get_data()->is_anyone_dead))
	{
		philo_think(((t_philo *)philo)->id);
		philo_eat(((t_philo *)philo));
		philo_sleep(((t_philo *)philo)->id);
	}
	return (NULL);
}

void init_threads(void)
{
	pthread_t	 	*pthread;
	t_data			*data;
	int				i;

	data = get_data();
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
	t_data *data;
	int	flag;

	data = get_data();
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