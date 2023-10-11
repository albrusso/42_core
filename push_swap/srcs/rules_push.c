/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:35:20 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/06 14:52:32 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_value *a, t_value *b, int bool)
{
	t_stack	*temp;

	if (b->lst == NULL)
		return ;
	temp = b->lst;
	b->lst = b->lst->next;
	temp->next = NULL;
	ft_lstadd_front(&a->lst, temp);
	if (bool == 1)
		write(1, "pa\n", 3);
}

void	pb(t_value *a, t_value *b, int bool)
{
	t_stack	*temp;

	if (a->lst == NULL)
		return ;
	temp = a->lst;
	a->lst = a->lst->next;
	temp->next = NULL;
	ft_lstadd_front(&b->lst, temp);
	if (bool == 1)
		write(1, "pb\n", 3);
}
