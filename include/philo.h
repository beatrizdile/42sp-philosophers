/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:21:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/12 15:07:36 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

#include "libft.h"
#include <stdio.h>

typedef struct s_data
{
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_times_to_eat;
}					t_data;

// input_error
int find_non_nums(char **argv);
int check_args(int argc, char **argv);

#endif