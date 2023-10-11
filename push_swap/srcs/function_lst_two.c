/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_lst_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:38:35 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/18 16:19:31 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_penultimate(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	if (temp == NULL || temp->next == NULL)
		return (NULL);
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

int	ft_isorder(t_stack **lst)
{
	int		number;
	t_stack	*temp;

	temp = (*lst);
	number = temp->content;
	temp = temp->next;
	while (temp != NULL)
	{
		if (number > temp->content)
			return (0);
		number = temp->content;
		temp = temp->next;
	}
	return (1);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstprint_tofirst(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (temp != NULL)
	{
		printf("%d ", temp->move_b);
		temp = temp->next;
	}
	printf("\n");
}

int	ft_lst_findposition(t_stack *lst, int n)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp != NULL && (temp->content != n))
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
