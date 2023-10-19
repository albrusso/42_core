/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:59:33 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/19 13:01:50 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	main(int argc, char *argv[])
{
	t_args	*args;
	t_philo	*philo;
	pthread_mutex_t	*forks;

	if (valid_args(argc, argv))
		return (-1);
	args = init_args(argv);
	forks = init_forks(args);
	philo = init_philo(args, forks);
	if (args->nbr_of_philo == 1)
		one_philo(philo);
	start(philo, forks, args);
	free_forks(philo, forks, args);
	free(args);
	
}