/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:18:56 by albrusso          #+#    #+#             */
/*   Updated: 2023/10/11 15:45:14 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include "libft/libft.h"

void	handler(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		i--;
	}
}

void	send_msg(char *msg, int pid)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		handler(msg[i], pid);
		i++;
	}
}

int	valid_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (ft_isdigit(pid[i]) == 1024)
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	if (ac != 3 || valid_pid(av[1]) == 0)
	{
		ft_putendl_fd("Invalid pid or number of arguments", 0);
		ft_putendl_fd("To execute\t./server <PID_ID> <string>", 1);
		return (0);
	}
	else
		send_msg(av[2], ft_atoi(av[1]));
}
