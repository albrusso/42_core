/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:18:59 by albrusso          #+#    #+#             */
/*   Updated: 2023/06/20 15:56:22 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "libft/libft.h"

void	handler(int signal)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
		c = (c << 1) | 1;
	else if (signal == SIGUSR2)
		c = (c << 1);
	usleep(200);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	write(1, "PID:\t", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		sleep(1);
	return (0);
}
