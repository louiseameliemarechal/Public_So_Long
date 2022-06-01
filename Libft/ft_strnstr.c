/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:17:25 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/07 15:13:36 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l_needle;

	l_needle = ft_strlen(needle);
	i = 0;
	if (!l_needle)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[i] && (i <= (len - l_needle)))
	{
		if (ft_strncmp(haystack + i, needle, l_needle) == 0)
			return ((char *) haystack + i);
		i++;
	}
	return (0);
}
