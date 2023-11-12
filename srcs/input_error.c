/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:05:59 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/12 15:06:23 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int find_non_nums(char **argv)
{
	int i;
	int j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (argv[i][j] != '\0' && argv[i][j] != '+' && !ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_args(int argc, char **argv)
{
	int i;

	i = 1;
	if ((argc == 6 || argc == 5) && !find_non_nums(argv))
		return (1);
	else
		printf("Error: Invalid parameters\n");
	return (0);
}
