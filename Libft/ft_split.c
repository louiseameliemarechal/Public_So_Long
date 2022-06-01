/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:44:00 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/07 16:22:59 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordlength(char const *str, unsigned int start, char sep)
{
	size_t	i;

	i = 0;
	while (str[start] && str[start] != sep)
	{	
		i++;
		start++;
	}
	return (i);
}

static int	ft_numberofsep(char const *str, char sep)
{
	int	index;
	int	cmpt;

	index = 0;
	cmpt = 0;
	if (str[0] == '\0')
		return (0);
	if (str[index] != sep)
		cmpt = 1;
	while (str[index])
	{
		if (str[index] == sep && str[index + 1] != sep
			&& str[index + 1] != '\0')
			cmpt++;
		index++;
	}
	return (cmpt);
}

char	**ft_split(char const *s, char c)
{
	char			**substring;
	int				index;
	int				len;
	unsigned int	start;

	start = 0;
	index = 0;
	len = ft_numberofsep(s, c);
	substring = malloc(sizeof(*substring) * (len + 1));
	if (substring == 0)
		return (0);
	substring[len] = 0;
	while (index < len)
	{
		while (s[start] == c)
			start++;
		substring[index] = ft_substr(s, start, ft_wordlength(s, start, c));
		start += ft_wordlength(s, start, c);
		index++;
	}
	return (substring);
}
