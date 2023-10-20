
#include "philo.h"

t_philo	*init_philo(t_args *args)
{
	t_philo	*philo;
	int	i;

	philo = malloc(sizeof(t_philo) * args->nbr_of_philo);
	if (!philo)
		error_exit(E_MALLOC, NULL, args->fork, args);
	i = 0;
	while (i < args->nbr_of_philo)
	{
		philo[i].nbr_of_philo = args->nbr_of_philo;
		philo[i].time_to_die = args->time_to_die;
		philo[i].time_to_eat = args->time_to_eat;
		philo[i].time_to_sleep = args->time_to_sleep;
		philo[i].nbr_of_time = args->nbr_of_time;
		philo[i].args = args;
		philo[i].philo_rang = i + 1;
		philo[i].meal_count = 0;
		philo[i].time_last_meal = 0;
		if (i == args->nbr_of_philo - 1)
		{
			philo[i].r_fork = &args->fork[i];
			philo[i].l_fork = &args->fork[(i + 1) % args->nbr_of_philo];
		}
		else
		{
			philo[i].r_fork = &args->fork[(i + 1) % args->nbr_of_philo];
			philo[i].l_fork = &args->fork[i];
		}
		i++;
	}
	return (philo);
}

void	supervisor(char *str, t_philo *philo)
{
	long long	time_to_print;
	bool	die;

	pthread_mutex_lock(&philo->args->root);
	die = philo->args->stop;
	pthread_mutex_unlock(&philo->args->root);
	if (die == false)
	{
		pthread_mutex_lock(&philo->args->print);
		time_to_print = get_time() - philo->time_start;
		printf("%lld %d %s", time_to_print, philo->philo_rang, str);
		pthread_mutex_unlock(&philo->args->print);
	}
}
