/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:48:38 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/07 16:16:51 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	ft_putnbr(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	ft_stringsize(int j)
{
	int	i;

	i = 0;
	if (j >= 0)
		i = ft_putnbr(j) + 1;
	else
		i = ft_putnbr(j) + 2;
	return (i);
}

char	*ft_itoa(int n)
{
	char		*number;
	int			i;
	long int	j;

	j = n;
	i = ft_stringsize(j);
	number = malloc(sizeof(*number) * (i + 1));
	if (number == 0)
		return (0);
	number[i] = '\0';
	if (j < 0)
	{
		number[0] = '-';
		j *= -1;
	}
	if (j == 0)
		number[0] = '0' + j;
	while (j > 9 && j != 0)
	{
		number[i - 1] = '0' + (j % 10);
		j /= 10;
		i--;
	}
	number[i - 1] = '0' + j;
	return (number);
}
