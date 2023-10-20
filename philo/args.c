
#include "philo.h"

bool	args_digit(int ac, char *av[])
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' && av[i][j] > '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	args_real(int ac, char *av[])
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
			return (false);
		i++;
	}
	return (true);
}

bool	valid_args(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		return (false);
	if (args_digit(ac, av))
		return (false);
	if(args_real(ac, av))
		return (false);
	return (true);
}

t_args	*init_args(char *av[])
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		error_exit(E_MALLOC, NULL, NULL, args);
	args->nbr_of_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		args->nbr_of_time = ft_atoi(av[5]);
	else
		args->nbr_of_time = -1;
	args->stop = false;
	args->time_start = 0;
	if (pthread_mutex_init(&args->root, NULL) != 0)
		error_exit(E_MUTEX_INIT, NULL, NULL, args);
	if (pthread_mutex_init(&args->print, NULL) != 0)
		error_exit(E_MUTEX_INIT, NULL, NULL, args);
	return (args);
}