/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:45:57 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/17 19:25:55 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo	*this_philo;

	this_philo = (t_philo *)philo;
	this_philo->last_meal_time = get_time();
	while (!(get_data()->stop_all))
	{
		philo_think(this_philo->id);
		if (get_data()->stop_all)
			break ;
		philo_eat(this_philo);
		if (get_data()->stop_all)
			break ;
		philo_sleep(this_philo->id);
		if (get_data()->stop_all)
			break ;
	}
	return (NULL);
}

void	print_die(t_philo *philos, int i)
{
	t_data	*data;

	data = get_data();
	pthread_mutex_lock(data->print);
	print_time();
	printf(" %d died\n", philos[i].id);
	pthread_mutex_unlock(data->print);
	data->printed_die = true;
}

void	*monitoring(void *ptr)
{
	int		i;
	t_philo	*philos;
	t_data	*data;

	data = get_data();
	ptr = NULL;
	philos = data->philos;
	while (!(data->stop_all))
	{
		i = -1;
		while (++i < data->num_of_philos)
		{
			if (check_death(&philos[i]))
			{
				data->stop_all = true;
				if (!data->printed_die)
					print_die(philos, i);
			}
			else if (philos[i].has_eaten_enough)
				everyone_has_eaten_enough(data);
		}
	}
	return (ptr);
}

void	init_threads(void)
{
	pthread_t	*pthread;
	t_data		*data;
	int			i;

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

int	main(int argc, char **argv)
{
	t_data	*data;
	int		flag;

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
