/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:45:57 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/16 18:34:23 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *philo)
{
	((t_philo *)philo)->last_meal_time = get_time();
	// ja comeu o suficiente?
	while(!(get_data()->is_anyone_dead) && !(((t_philo *)philo)->is_dead) \
	&& !eat_enough(philo))
	{
		philo_think(((t_philo *)philo)->id);
		if(check_death((t_philo *)philo) || get_data()->is_anyone_dead)
			break;
		philo_eat(((t_philo *)philo));
		if(check_death((t_philo *)philo) || get_data()->is_anyone_dead)
			break;
		philo_sleep(((t_philo *)philo)->id);
		if(check_death((t_philo *)philo) || get_data()->is_anyone_dead)
			break;
	}
	if (!get_data()->printed_die && !eat_enough(philo))
	{
		pthread_mutex_lock(get_data()->print);
		print_time();
		printf(" %d died\n", ((t_philo *)philo)->id);
		pthread_mutex_unlock(get_data()->print);
		get_data()->printed_die = 1;
	}
	return (NULL);
}

void *monitoring()
{
	int i;

	while (!(get_data()->is_anyone_dead))
	{
		i = 0;
		while(i < get_data()->num_of_philos)
		{
			if (check_death(&get_data()->philos[i]))
				get_data()->is_anyone_dead = 1;
			i++;
		}
	}
	return (NULL);
}

void init_threads(void)
{
	pthread_t	 	*pthread;
	t_data			*data;
	int				i;

	data = get_data();
	pthread = ft_calloc(data->num_of_philos + 1, sizeof(pthread_t));
	i = -1;
	while (++i < data->num_of_philos)
	{
		data->philos[i].last_meal_time = get_time();
		pthread_create(&pthread[i], NULL, &routine, (void *)&data->philos[i]);
	}
	pthread_create(&pthread[i], NULL, &monitoring, NULL);
	i = -1;
	while (++i < data->num_of_philos + 1)
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
	{
		set_data(argc, argv);	
		one_philo();
		free_for_finish(get_data());
	}
	else if (flag == 2)
	{
		set_data(argc, argv);
		init_threads();
		free_for_finish(get_data());
	}
	return (0);
}

// dps de pensar: come, dps de comer: dorme, dps de dormir: pensa
// tira a libft