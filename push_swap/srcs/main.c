/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:37:53 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/18 17:44:49 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_main(t_value *a, t_value *b, char *argv[], int k)
{
	int	i;

	if (k == 1)
		i = 1;
	else
		i = 2;
	a->lst = ft_lstnew(ft_atoi(argv[i - 1]));
	b->lst = NULL;
	while (i < a->ac)
	{
		ft_lstadd_back(&a->lst, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	if (ft_isorder(&a->lst) == 1)
		return ;
	if (a->ac == 3)
		ft_two_nbr(a);
	if (a->ac == 4)
		ft_three_numbers(a, 0);
	if (a->ac == 5 || a->ac == 6)
		ft_five_numbers(a, b);
	if (a->ac >= 7)
		ft_onehundred_numbers(a, b);
}

t_stack	*ft_free(t_stack *lst)
{
	t_stack	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
	lst = NULL;
	return (lst);
}

int	main(int argc, char *argv[])
{
	t_value	a;
	t_value	b;
	int		k;

	k = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_new_argc(argv);
		k = 1;
	}
	if (argc < 2)
		ft_close(k, argv);
	a.ac = argc;
	if (ft_check_num(a.ac, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		ft_main(&a, &b, argv, k);
	if (k == 1)
		ft_second_free(argv);
	a.lst = ft_free(a.lst);
	return (0);
}
