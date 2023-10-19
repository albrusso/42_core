
#include "philo.h"

void	free_forks(t_philo *philo, pthread_mutex_t *forks, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_of_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		philo[i].l_fork = NULL;
		philo[i].r_fork = NULL;
		i++;
	}
	free(forks);
	forks = NULL;
	if (philo)
	{
		free(philo);
		philo = NULL;
	}
}
