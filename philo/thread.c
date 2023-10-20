
#include "philo.h"

void	start(t_philo *philo, t_args *args)
{
	int	i;

	philo->args->time_start = get_time();
	if (pthread_create(&philo->args->die, NULL, philo_die, (void *)philo) != 0)
		error_exit(E_THREAD_CREATE, philo, args->fork, args);
	i = 1;
	while (i < args->nbr_of_philo)
	{
		if (pthread_create(&philo[i].philo_thread, NULL, routine, (void *)&philo[i]) != 0)
			error_exit(E_THREAD_CREATE, philo, args->fork, args);
		i += 2;
	}
	i = 0;
	while (i < args->nbr_of_philo)
	{
		if (pthread_create(&philo[i].philo_thread, NULL, routine, (void *)&philo[i]) != 0)
			error_exit(E_THREAD_CREATE, philo, args->fork, args);
		i += 2;
	}
	i = 0;
	if (pthread_join(philo->args->die, NULL) != 0)
			error_exit(E_JOIN, philo, args->fork, args);
	while (i < args->nbr_of_philo)
	{
		if (pthread_join(philo[i].philo_thread, NULL) != 0)
			error_exit(E_JOIN, philo, args->fork, args);
		i++;
	}
}