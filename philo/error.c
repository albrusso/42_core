
#include "philo.h"

void	free_all(t_philo *p, pthread_mutex_t *f, t_args *a)
{
	int	i;

	i = 0;
	while (i < a->nbr_of_philo)
	{
		pthread_mutex_destroy(&a->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&a->root);
	pthread_mutex_destroy(&a->print);
	if(f != NULL)
		free(f);
	if (a != NULL)
		free(a);
	if (p != NULL)
		free(p);
}

void	error_exit(char *msg, t_philo *philo, pthread_mutex_t *forks, t_args *args)
{
	int	i;

	i = 0;
	if (msg != NULL)
		printf("Error: %s\n", msg);
	free_all(philo, forks, args);
}