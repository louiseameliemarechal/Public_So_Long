/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:48:21 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/07 16:38:36 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	max_size;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_calloc(sizeof(*str), 1));
	max_size = (ft_strlen(s) - start);
	if (len > max_size)
		len = max_size;
	str = malloc(sizeof(*str) * (len + 1));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
