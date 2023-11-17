/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:21:13 by bedos-sa          #+#    #+#             */
/*   Updated: 2023/11/17 18:22:47 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

#define TOLERANCE 1

typedef struct s_philo
{
	int				id;
	int				id_fork_left;
	int				id_fork_right;
	_Atomic bool	is_dead;
	_Atomic int		num_meals;
	_Atomic long	last_meal_time;
	_Atomic bool	has_eaten_enough;
}					t_philo;

typedef struct s_data
{
	int				num_of_philos;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	_Atomic int		num_times_to_eat;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	_Atomic int		stop_all;
	_Atomic int		printed_die;
	_Atomic long	start_time;
}					t_data;

// checks
int					check_args(int argc, char **argv);
bool				check_death(t_philo *philo);

// monitoring
void				*monitoring(void *ptr);

// one_philo
void				one_philo(void);

// free_all
void				free_for_finish(t_data *data);

// print
void				print_time(void);

// data
t_data				*get_data(void);
void				set_data(int argc, char **argv);

// time
long int			get_time(void);

// sleep
void				philo_sleep(int id);

// think
void				philo_think(int id);

// eat
void				philo_eat(t_philo *philo);
void				everyone_has_eaten_enough(t_data *data);

// utils
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isdigit(int c);
size_t				ft_strlen(char *str);
void				*ft_memset(void *s, int c, size_t x);

#endif
