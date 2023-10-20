
#include "philo.h"

pthread_mutex_t	*init_forks(t_args *args)
{
	int	i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * args->nbr_of_philo);
	if(!forks)
		error_exit(E_MALLOC, NULL, forks, args);
	while (i < args->nbr_of_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			error_exit(E_MUTEX_INIT, NULL, forks, args);
		i++;
	}
	return (forks);
}

void	take_fork(t_philo *philo)
{
	if (philo->philo_rang % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		supervisor(P_TAKE_FORK, philo);
		pthread_mutex_lock(philo->r_fork);
		supervisor(P_TAKE_FORK, philo);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		supervisor(P_TAKE_FORK, philo);
		pthread_mutex_lock(philo->l_fork);
		supervisor(P_TAKE_FORK, philo);
	}
}

void	drop_fork(t_philo *philo)
{
	if (philo->philo_rang % 2 == 0)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}