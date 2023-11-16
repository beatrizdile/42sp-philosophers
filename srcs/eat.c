/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:05:40 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/16 14:20:29 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat_even(t_philo *philo)
{
	pthread_mutex_lock(&get_data()->forks[philo->id_fork_right]);
	pthread_mutex_lock(&get_data()->forks[philo->id_fork_left]);
	pthread_mutex_lock(get_data()->print);
	print_time();
	printf(" %d is eating\n", philo->id);
	pthread_mutex_unlock(get_data()->print);
	usleep(get_data()->time_to_eat);
	pthread_mutex_unlock(&get_data()->forks[philo->id_fork_right]);
	pthread_mutex_unlock(&get_data()->forks[philo->id_fork_left]);
}

void eat_odd(t_philo *philo)
{
	pthread_mutex_lock(&get_data()->forks[philo->id_fork_left]);
	pthread_mutex_lock(&get_data()->forks[philo->id_fork_right]);
	pthread_mutex_lock(get_data()->print);
	print_time();
	printf(" %d is eating\n", philo->id);
	pthread_mutex_unlock(get_data()->print);
	usleep(get_data()->time_to_eat);
	pthread_mutex_unlock(&get_data()->forks[philo->id_fork_left]);
	pthread_mutex_unlock(&get_data()->forks[philo->id_fork_right]);
}

void philo_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		eat_even(philo);
	else
		eat_odd(philo);
}
