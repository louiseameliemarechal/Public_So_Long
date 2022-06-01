/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:44:18 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/17 13:44:23 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_cmpt_hexa(unsigned long long int x)
{
	int	len;

	len = 0;
	while (x > 15)
	{
		len += 1;
		x /= 16;
	}
	return (len + 1);
}

int	ft_putnbr_hexa(unsigned int x, char c)
{
	long int	y;
	char		*base;
	int			cmpt;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	y = x;
	cmpt = 0;
	if (y < 0)
	{
		ft_putchar('-');
		y *= -1;
		cmpt += 1;
	}
	if (y > 15)
		ft_putnbr_hexa(y / 16, c);
	ft_putchar(base[y % 16]);
	return (ft_cmpt_hexa(y) + cmpt);
}

int	ft_putnbr_long_hexa(unsigned long long int y)
{
	char	*base;

	base = "0123456789abcdef";
	if (y > 15)
		ft_putnbr_long_hexa(y / 16);
	ft_putchar(base[y % 16]);
	return (ft_cmpt_hexa(y));
}
