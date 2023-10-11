/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:08:20 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/06 14:51:04 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_value	*a, int bool)
{
	int		temp;

	temp = a->lst->content;
	a->lst->content = a->lst->next->content;
	a->lst->next->content = temp;
	if (bool == 1)
		write(1, "sa\n", 3);
}

void	sb(t_value *b, int bool)
{
	int		temp;

	temp = b->lst->content;
	b->lst->content = b->lst->next->content;
	b->lst->next->content = temp;
	if (bool == 1)
		write (1, "sb\n", 3);
}

void	ss(t_value *a, t_value *b, int bool)
{
	sa(a, 0);
	sb(b, 0);
	if (bool == 1)
		write(1, "ss\n", 3);
}
