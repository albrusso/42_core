
#include "philo.h"

void	start(t_philo *philo, pthread_mutex_t *forks, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_of_philo)
	{
		philo[i].time_start = get_time();
		if (pthread_create(&philo[i].philo_thread, NULL, routine, (void *)&philo[i]) != 0)
			error_exit(E_THREAD_CREATE, philo, forks, args);
		i++;
	}
	i = 0;
	while (i < args->nbr_of_philo)
	{
		if (pthread_join(philo[i].philo_thread, NULL) != 0)
			error_exit(E_JOIN, philo, forks, args);
		i++;
	}
}