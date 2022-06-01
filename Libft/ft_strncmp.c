/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <lmarecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:07:08 by lmarecha          #+#    #+#             */
/*   Updated: 2022/04/05 12:27:29 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	x;

	i = n - 4;
	x = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[x])
	{
		if (i == n - 1)
			return (s1[i] - s2[x]);
		i++;
		x++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
