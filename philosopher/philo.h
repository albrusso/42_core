/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:16 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/12 16:32:08 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define ARGS "Args will be: ./philo [nbr_philo] [time_die] [time_eat] [time_sleep] ([nbr_repeat])"

typedef struct s_fork
{
	int	r;
	int	l;
}		t_fork;

typedef struct s_philo
{
	int	id;
	int	meal_count;
	long long	last_meal;
	t_fork	f;
	pthread_t	t;
}		t_philo;

typedef struct s_data
{
	int	p_nbr;
	long long	t_die;
	long long	t_eat;
	long long	t_sleep;
	int	r_nbr;
	long long	t_start;
	t_philo	*p;
	pthread_mutex_t	*f;
	pthread_mutex_t	m;
}		t_data;

//init.c


//utils.c
int	ft_atoi(const char *str);

#endif