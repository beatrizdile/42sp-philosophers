/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:45:57 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 12:28:18 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void *philo(/*void *param*/)
{
	printf("philo created\n");
	return (NULL);
}

void create_philos(int num)
{
	printf("created %d philos\n", num);
	pthread_t	thread1;
	pthread_create(&thread1, NULL, philo, NULL);
	pthread_join(thread1, NULL);
}

t_data *get_data(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = ft_calloc(1, sizeof(t_data));
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
	i = 0;
	while (i < data->num_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].id_fork_left = i;
		data->philos[i].id_fork_right = (i + 1) % data->num_of_philos;
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (data);
}

void routine(t_philo philo)
{
	(void) philo;
	printf("routineee");
	// while(/*alguem morreu && ja comeu tudo*/)
	// {
	// 	philo_think();
	// 	philo_eat();
	// 	philo_sleep();
	// }
	
}

int main(int argc, char **argv)
{
	t_data *data;
	int	flag;

	flag = check_args(argc, argv);
	if (flag == 1)
		one_philo();
	else if (flag == 2)
	{
		printf("not one philo, everything is fine");
		data = get_data(argc, argv);
		free_for_finish(data);
	}
	return (0);
}

// dps de pensar: come, dps de comer: dorme, dps de dormir: pensa