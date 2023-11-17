/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:05:40 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/17 18:54:18 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_even(t_philo *philo)
{
	const t_data *data = get_data();
	
	pthread_mutex_lock(&data->forks[philo->id_fork_right]);
	pthread_mutex_lock(data->print);
	if (!data->printed_die)
		print_time();
	if (!data->printed_die)
		printf(" %d has taken a fork\n", philo->id);
	pthread_mutex_unlock(data->print);
	pthread_mutex_lock(&data->forks[philo->id_fork_left]);
	philo->last_meal_time = get_time();
	pthread_mutex_lock(data->print);
	if (!data->printed_die)
	{
		print_time();
		printf(" %d has taken a fork\n", philo->id);
		print_time();
		printf(" %d is eating\n", philo->id);
	}
	pthread_mutex_unlock(data->print);
	usleep(data->time_to_eat * 1000);
	philo->num_meals++;
	pthread_mutex_unlock(&data->forks[philo->id_fork_right]);
	pthread_mutex_unlock(&data->forks[philo->id_fork_left]);
}

void	eat_odd(t_philo *philo)
{
	const t_data *data = get_data();

	pthread_mutex_lock(&data->forks[philo->id_fork_left]);
	pthread_mutex_lock(data->print);
	if (!data->printed_die)
		print_time();
	if (!data->printed_die)
		printf(" %d has taken a fork\n", philo->id);
	pthread_mutex_unlock(data->print);
	pthread_mutex_lock(&data->forks[philo->id_fork_right]);
	philo->last_meal_time = get_time();
	pthread_mutex_lock(data->print);
	if (!data->printed_die)
	{
		print_time();
		printf(" %d has taken a fork\n", philo->id);
		print_time();
		printf(" %d is eating\n", philo->id);
	}
	pthread_mutex_unlock(data->print);
	usleep(data->time_to_eat * 1000);
	philo->num_meals++;
	pthread_mutex_unlock(&data->forks[philo->id_fork_left]);
	pthread_mutex_unlock(&data->forks[philo->id_fork_right]);
}

void	philo_eat(t_philo *philo)
{
	const int times_to_eat = get_data()->num_times_to_eat;
	if (times_to_eat != -1)
		philo->has_eaten_enough = (philo->num_meals >= times_to_eat);
	if (philo->id % 2 == 0)
		eat_even(philo);
	else
		eat_odd(philo);
}

void	everyone_has_eaten_enough(t_data *data)
{
	int				i;
	const int		philo_num = data->num_of_philos;
	const t_philo	*philos = data->philos;

	i = 0;
	while(i < philo_num)
	{
		if(!philos[i].has_eaten_enough)
			return ;
		i++;
	}
	get_data()->stop_all = true;
}
