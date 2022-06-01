/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:32:03 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/07 10:12:12 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*space;
	size_t	memory;

	memory = size * count;
	space = malloc(memory);
	if (space == 0)
		return (0);
	ft_bzero(space, memory);
	return (space);
}
