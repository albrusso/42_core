/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:33:21 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/06 14:47:45 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_value *a, int bool)
{
	t_stack	*temp;

	temp = ft_penultimate(a->lst);
	ft_lstadd_front(&a->lst, ft_lstlast(a->lst));
	temp->next = NULL;
	if (bool == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_value *b, int bool)
{
	t_stack	*temp;

	temp = ft_penultimate(b->lst);
	ft_lstadd_front(&b->lst, ft_lstlast(b->lst));
	temp->next = NULL;
	if (bool == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_value *a, t_value *b, int bool)
{
	rra(a, 0);
	rrb(b, 0);
	if (bool == 1)
		write(1, "rrr\n", 4);
}
