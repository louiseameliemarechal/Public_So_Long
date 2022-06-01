/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:28:15 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/06 17:18:13 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l_dst;
	size_t	l_src;

	l_src = ft_strlen((char *)src);
	l_dst = ft_strlen(dst);
	if (dstsize < l_dst)
		return (dstsize + l_src);
	else
	{
		dst = dst + l_dst;
		ft_strlcpy(dst, src, (dstsize - l_dst));
		return (l_dst + l_src);
	}
}
