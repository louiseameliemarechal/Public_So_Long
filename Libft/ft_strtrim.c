/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:29:58 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/07 16:24:54 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	ft_issep(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_occurence(char const *s1, char const *set)
{
	int	index;
	int	s_len;

	s_len = ft_strlen(s1) - 1;
	index = 0;
	while (ft_issep(s1[index], set))
		index ++;
	if ((size_t)index == ft_strlen(s1))
		return (index);
	while (ft_issep(s1[s_len], set))
	{	
		s_len--;
		index ++;
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		max_size;
	int		index;
	int		j;

	max_size = ft_strlen(s1) - ft_occurence(s1, set);
	cpy = malloc(sizeof(*cpy) * (max_size + 1));
	if (cpy == 0)
		return (0);
	index = 0;
	j = 0;
	if (max_size != 0)
	{
		while (ft_issep(s1[index], set))
			index ++;
		while (max_size > 1 && ft_issep(s1[max_size - 1], set))
			max_size--;
		while (j < max_size)
		{
			cpy[j] = s1[index++];
			j++;
		}
	}
	cpy[j] = '\0';
	return (cpy);
}
