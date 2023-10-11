/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:47:34 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/11 16:34:00 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct	s_philo
{
	int	n_id;
	int	n_meal;
	long long	last_meal;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_data	*data;
}		t_philo;

typedef struct	s_data
{
	int	nbr_philo;
	int	nbr_repeat;
	long long	time_eat;
	long long	time_sleep;
	long long	time_die;
	pthread_t	*t_id;
	pthread_mutex_t	mutex;
}		t_data;

int	ft_atoi(const char *str);

#endif