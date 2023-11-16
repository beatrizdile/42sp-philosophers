/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:52:14 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/16 17:39:25 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool check_death(t_philo *philo)
{
	long long	time_since_last_meal;

	time_since_last_meal = get_time() - philo->last_meal_time;
	if (time_since_last_meal > get_data()->time_to_die)
	{
		philo->is_dead = true;
		get_data()->is_anyone_dead = true;
	}
	return (philo->is_dead);
}