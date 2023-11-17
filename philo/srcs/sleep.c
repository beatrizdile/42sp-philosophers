/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:26:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/17 13:07:18 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(int id)
{
	pthread_mutex_lock(get_data()->print);
	print_time();
	printf(" %d is sleeping\n", id);
	pthread_mutex_unlock(get_data()->print);
	usleep(get_data()->time_to_sleep * 1000);
}
