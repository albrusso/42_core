/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:02:16 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/13 15:36:31 by albrusso         ###   ########.fr       */
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

# define ARGS "Args will be: ./philo [nbr_philo] [time_die] [time_eat] [time_sleep] ([nbr_repeat])\n"
# define DIE "is died\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define FORK "taken a fork\n"
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
	struct s_data	*d;
}		t_philo;

typedef struct s_data
{
	int	p_nbr;
	int	t_id;
	long long	t_die;
	long long	t_eat;
	long long	t_sleep;
	int	r_nbr;
	long long	t_start;
	bool	stop;
	t_philo	*p;
	pthread_mutex_t	*f;
	pthread_mutex_t	m;
	pthread_mutex_t	s;
}		t_data;

//init.c
bool	valid_args(int ac, char *av[]);
void	init_data(int ac, char *av[], t_data *d);
void	init_philo(t_data *d);

//utils.c
int	ft_atoi(const char *str);
long long get_time();
void	print(t_data *d, int i, char *s);

//routine.c
void	*routine(void *_d);
void	all_eat(t_data *d);

//action.c
void	p_sleep(t_data *d, int i);
void	p_eat(t_data *d, int i);
void	p_die(t_data *d, int i);

//main.c
void	launch_thread(t_data *d);

#endif