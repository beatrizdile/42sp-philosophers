/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:45:57 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/12 15:29:35 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void *philo(/*void *param*/)
{
	printf("philo created\n");
	return (NULL);
}

void create_philos(int num)
{
	printf("created %d philos\n", num);
	pthread_t	thread1;
	pthread_create(&thread1, NULL, philo, NULL);
	pthread_join(thread1, NULL);
}

int main(int argc, char **argv)
{
	if (check_args(argc, argv))
	{
		// create_philos(1);
	}
	return (0);
}
