/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:34:09 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/17 13:43:10 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

int	ft_cmpt(long int x)
{
	int	len;

	len = 0;
	while (x > 9)
	{
		len += 1;
		x /= 10;
	}
	return (len + 1);
}

int	ft_putnbr(int x)
{
	long int	y;
	int			cmpt;

	cmpt = 0;
	y = x;
	if (y < 0)
	{
		ft_putchar('-');
		y *= -1;
		cmpt += 1;
	}
	if (y > 9)
		ft_putnbr(y / 10);
	ft_putchar('0' + (y % 10));
	return (ft_cmpt(y) + cmpt);
}

int	ft_unsigned_putnbr(unsigned int x)
{
	long unsigned int	y;
	int					cmpt;

	cmpt = 0;
	y = x;
	if (y < 0)
	{
		ft_putchar('-');
		y *= -1;
		cmpt += 1;
	}
	if (y > 9)
	{	
		ft_putnbr(y / 10);
	}
	ft_putchar('0' + (y % 10));
	return (ft_cmpt(y) + cmpt);
}
