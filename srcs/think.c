/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:26:16 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/16 14:20:16 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_think(int id)
{
	pthread_mutex_lock(get_data()->print);
	print_time();
	printf(" %d is thinking\n", id);
	pthread_mutex_unlock(get_data()->print);
	usleep(10000);
}
