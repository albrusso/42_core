/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:47:20 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/13 16:01:05 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>

//string philo routine
# define P_TAKE_FORK "has taken a fork\n"
# define P_EAT "is eating\n"
# define P_SLEEP "is sleeping\n"
# define P_THINK "is thinking\n"
# define P_DIE "died\n"

//string for error
# define E_MALLOC "something in malloc() was wrong\n"
# define E_MUTEX_INIT "mutex init failed\n"
# define E_THREAD_CREATE "thread create failed\n"
# define E_JOIN "thread join failed\n"

//struct of arguments data
typedef struct s_args
{
	int	nbr_of_philo;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int	nbr_of_time;
	pthread_mutex_t	root;
}				t_args;

//struct of philosopher
typedef struct s_philo
{
	t_args	*args;
	int	philo_rang;
	int	meal_count;
	long int	time_last_meal;
	long long	time_start;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_t	philo_thread;
}				t_philo;

//args.c
bool	valid_args(int ac, char *av[]);
bool	args_real(int ac, char *av[]);
bool	args_digit(int ac, char *av[]);
t_args	*init_args(char *av[]);

//philo.c
t_philo	*init_philo(t_args *args, pthread_mutex_t *forks);
void	supervisor(char *str, t_philo *philo);

//forks.c
pthread_mutex_t	*init_forks(t_args *args);
void	take_fork(t_philo *philo);
void	drop_fork(t_philo *philo);

//thread.c
void	start(t_philo *philo, pthread_mutex_t *forks, t_args *args);

//routine.c
void  *routine(void *_philo);

//action.c
void  p_eat(t_philo *philo);
void  p_sleep(t_philo *philo);
bool  philo_die(t_philo *philo);

//error.c
void	error_exit(char *msg, t_philo *philo, pthread_mutex_t *forks, t_args *args);

//utils.c
int	ft_atoi(const char *str);
long long	get_time(void);

//free.c
void	free_forks(t_philo *philo, pthread_mutex_t *forks, t_args *args);

#endif