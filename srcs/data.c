/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:35:45 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 17:14:58 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_data *get_data()
{
	static t_data data;

	return (&data);
}


void set_data(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = get_data();
	data->start_time = get_time();
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_times_to_eat = ft_atoi(argv[5]);
	else if (argc == 5)
		data->num_times_to_eat = -1;
	data->philos = ft_calloc(1, sizeof(t_philo) * data->num_of_philos);
	data->forks = ft_calloc(1, sizeof(pthread_mutex_t) * data->num_of_philos);
	i = -1;
	while (++i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].id_fork_left = i;
		data->philos[i].id_fork_right = (i + 1) % data->num_of_philos;
		pthread_mutex_init(&data->forks[i], NULL);
	}
}
