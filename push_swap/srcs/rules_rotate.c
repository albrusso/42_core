/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:31:21 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/06 14:50:27 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_value *a, int bool)
{
	t_stack	*head;

	head = a->lst;
	ft_lstlast(a->lst)->next = a->lst;
	a->lst = a->lst->next;
	head->next = NULL;
	if (bool == 1)
		write(1, "ra\n", 3);
}

void	rb(t_value *b, int bool)
{
	t_stack	*head;

	head = b->lst;
	ft_lstlast(b->lst)->next = b->lst;
	b->lst = b->lst->next;
	head->next = NULL;
	if (bool == 1)
		write(1, "rb\n", 3);
}

void	rr(t_value *a, t_value *b, int bool)
{
	ra(a, 0);
	rb(b, 0);
	if (bool == 1)
		write(1, "rr\n", 3);
}
