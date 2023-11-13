/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:26:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/13 17:41:05 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_sleep(int id)
{
	pthread_mutex_lock(&get_data()->print);
	printf(" %d is sleeping\n", id);
	usleep(get_data()->time_to_sleep);
	pthread_mutex_unlock(&get_data()->print);
}
