/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:52:32 by albrusso          #+#    #+#             */
/*   Updated: 2023/04/04 12:53:55 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	leng(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i + 1);
}

char	**ft_split(char *s1, char c)
{
	char	**arr;
	int		total;
	int		len;
	int		i;

	i = 0;
	total = ft_counter(s1, c);
	arr = ft_calloc(total * sizeof(char *), 1);
	if (!arr)
		return (NULL);
	while (*s1 && i < total && total != 1)
	{
		while (*s1 == c)
			s1++;
		len = leng(s1, c);
		arr[i] = malloc(len);
		if (!arr[i])
			return (NULL);
		ft_strlcpy(arr[i], s1, len);
		i++;
		s1 += len - 1;
	}
	return (arr);
}

void	ft_second_free(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

char	*ft_strdup(const char *str)
{
	size_t		i;
	size_t		j;
	char		*ptr;

	i = ft_strlen(str);
	ptr = (char *)malloc(i + 1);
	if (ptr == NULL)
		return (0);
	j = 0;
	while (j < i)
	{
		ptr[j] = str[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
