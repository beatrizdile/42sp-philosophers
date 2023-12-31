/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:05:59 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/17 13:07:09 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// check_args returns 1 if there is only one philo, returns 2 if there are more
// and returns 0 something is invalid.

#include "philo.h"

int	find_non_nums(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (ft_strlen(argv[i]) == 0)
			return (1);
		while (argv[i][j])
		{
			if (argv[i][j] != '\0' && !ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	invalid_nums(char **argv)
{
	if (ft_atoi(argv[1]) == 0 || ft_atoi(argv[1]) > 200)
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if ((argc == 6 || argc == 5) && !find_non_nums(argv) && !invalid_nums(argv))
	{
		if (ft_atoi(argv[1]) == 1)
			return (1);
		else
			return (2);
	}
	else
		printf("Error: Invalid parameters\n");
	return (0);
}
