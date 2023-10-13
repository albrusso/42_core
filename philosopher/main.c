/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:59:33 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/13 16:01:08 by albrusso         ###   ########.fr       */
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
	start(philo, forks, args);
	free_forks(philo, forks, args);
	free(args);
	
}
