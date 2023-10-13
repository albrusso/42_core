
#include "philo.h"

t_philo	*init_philo(t_args *args, pthread_mutex_t *forks)
{
	t_philo	*philo;
	int	i;

	philo = malloc(sizeof(t_philo) * args->nbr_of_philo);
	if (!philo)
		error_exit(E_MALLOC, NULL, forks, args);
	i = 0;
	while (i < args->nbr_of_philo)
	{
		philo[i].args = args;
		philo[i].philo_rang = i + 1;
		philo[i].meal_count = 0;
		philo[i].time_last_meal = 0;
		philo[i].r_fork = &forks[(i + 1) % args->nbr_of_philo];
		philo[i].l_fork = &forks[i];
		i++;
	}
	return (philo);
}

void	supervisor(char *str, t_philo *philo)
{
	long long	time_to_print;

	pthread_mutex_lock(&philo->args->root);
	time_to_print = get_time() - philo->time_start;
	printf("%lld %d %s", time_to_print, philo->philo_rang, str);
	pthread_mutex_unlock(&philo->args->root);
}