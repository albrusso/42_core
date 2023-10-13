
#include "philo.h"

void	error_exit(char *msg, t_philo *philo, pthread_mutex_t *forks, t_args *args)
{
	printf("Error: %s\n", msg);
	if (&fork != NULL)
		free_forks(philo, forks, args);
	if (args != NULL)
		free(args);
	exit(0);
}