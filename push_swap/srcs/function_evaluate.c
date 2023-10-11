/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_evaluate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:07:40 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/31 17:29:32 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_set_position_two(t_value *a, t_stack *b, t_stack *lst_a, t_stack *lst_b)
{
	int	count;

	count = 0;
	while (lst_a->next != NULL && !((lst_b->content < lst_a->next->content)
			&& (lst_b->content > lst_a->content)))
	{
		if (b->content > a->max)
		{
			count = ft_lst_findposition(a->lst, a->max);
			break ;
		}
		if (b->content < a->min)
		{
			count = ft_lst_findposition(a->lst, a->min);
			count--;
			break ;
		}
		lst_a = lst_a->next;
		count++;
	}
	return (count);
}

void	ft_tofirst(t_value *b)
{
	int		distance;
	int		lstsize;
	t_stack	*temp;

	lstsize = ft_lstsize(b->lst);
	if (b->lst == NULL)
		return ;
	distance = 0;
	temp = b->lst;
	while (temp != NULL)
	{
		if (distance <= lstsize / 2 || lstsize == 1)
			temp->move_b = distance;
		else
			temp->move_b = distance - lstsize;
		distance++;
		temp = temp->next;
	}
}

void	ft_set_topush(t_value *a, int number)
{
	t_stack	*temp;

	temp = a->lst;
	while (temp != NULL)
	{
		temp = a->lst;
		while (temp->content != number)
			temp = temp->next;
		temp->to_push = 1;
		temp = temp->next;
		while (1)
		{
			if (temp != NULL && temp->content < number)
				temp = temp->next;
			else
				break ;
		}
		if (temp)
		{
			temp->to_push = 1;
			number = temp->content;
		}
	}	
}

void	ft_add_tob(t_value *a, t_value *b)
{
	t_stack	*temp;
	int		sizelst;

	sizelst = ft_lstsize(a->lst);
	temp = a->lst;
	while (sizelst > 0)
	{
		if (temp->to_push == 0)
		{
			while (temp->content != a->lst->content)
				ra(a, 1);
			pb(a, b, 1);
			temp = a->lst;
		}
		else
		{
			if (sizelst == 1 && temp->content == ft_find_max(a->lst))
				ra(a, 1);
			temp = temp->next;
		}
		sizelst--;
	}
}

int	ft_set_position(t_value *a, t_stack *b, int lstsize)
{
	int		count;
	t_stack	*lst_a;
	t_stack	*lst_b;

	lst_a = a->lst;
	lst_b = b;
	count = 0;
	a->min = ft_find_min(a->lst);
	a->max = ft_find_max(a->lst);
	count = ft_set_position_two(a, b, lst_a, lst_b) + 1;
	if (count > lstsize / 2)
		count = count - lstsize;
	return (count);
}
