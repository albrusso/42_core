/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_evaluate_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:06:35 by albrusso          #+#    #+#             */
/*   Updated: 2023/03/31 14:12:10 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_while(t_stack *temp, int current, int count)
{
	while (temp != NULL)
	{
		if (current < temp->content)
		{
			count++;
			current = temp->content;
		}
		temp = temp->next;
	}
	return (count);
}

int	ft_sorted_sequence_two(t_stack *lst_a, int ret, int count)
{
	t_stack	*temp;
	int		top;
	int		current;

	top = 0;
	while (lst_a != NULL)
	{
		count = 0;
		temp = lst_a->next;
		current = lst_a->content;
		count = ft_while(temp, current, count) + 1;
		if (top < count)
		{
			top = count;
			ret = lst_a->content;
		}
		lst_a = lst_a->next;
	}
	return (ret);
}

int	ft_sorted_sequence(t_value *a)
{
	int		count;
	int		ret;
	t_stack	*lst_a;

	ret = 0;
	count = 0;
	lst_a = a->lst;
	ret = ft_sorted_sequence_two(lst_a, ret, count);
	return (ret);
}

void	ft_set_foraa(t_value *a, t_value *b, int lstsize)
{
	int		a_lstsize;
	int		i;
	t_stack	*lst_b;

	lst_b = b->lst;
	a_lstsize = ft_lstsize(a->lst);
	i = 0;
	while (i < lstsize && lst_b != NULL)
	{
		lst_b->move_a = ft_set_position(a, lst_b, a_lstsize);
		lst_b = lst_b->next;
		i++;
	}
}

void	ft_set_fora(t_value *a, t_value *b)
{
	int		lstsize;

	lstsize = ft_lstsize(b->lst);
	ft_set_foraa(a, b, lstsize);
}
