/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:29:17 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/17 13:00:27 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RETURN VALUE: The strlen() function returns the number of bytes in the 
// string str.

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
