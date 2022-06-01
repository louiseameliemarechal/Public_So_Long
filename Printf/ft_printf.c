/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:11:24 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/17 13:42:49 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "ft_printf.h"

int	ft_find_type(const char *last, int cmpt, va_list lst)
{
	while (*last)
	{
		if (*last == '%')
		{
			last++;
			if (*last == '%')
				cmpt += ft_putchar(*last);
			else if (*last == 'c')
				cmpt += ft_putchar(va_arg(lst, int));
			else if (*last == 's')
				cmpt += ft_putstr(va_arg(lst, char *));
			else if (*last == 'p')
				cmpt += ft_putptr(va_arg(lst, void *));
			else if (*last == 'd' || *last == 'i')
				cmpt += ft_putnbr(va_arg(lst, int));
			else if (*last == 'u')
				cmpt += ft_unsigned_putnbr(va_arg(lst, unsigned int));
			else if (*last == 'x' || *last == 'X')
				cmpt += ft_putnbr_hexa(va_arg(lst, unsigned int), *last);
		}
		else
			cmpt += ft_putchar(*last);
		last++;
	}
	return (cmpt);
}

int	ft_printf(const char *last, ...)
{
	va_list	lst;
	int		cmpt;

	cmpt = 0;
	va_start (lst, last);
	cmpt = ft_find_type(last, cmpt, lst);
	va_end(lst);
	return (cmpt);
}
