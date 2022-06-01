/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:42:18 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/17 13:42:23 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int x);
int	ft_putnbr_hexa(unsigned int x, char c);
int	ft_putnbr_long_hexa(unsigned long long int y);
int	ft_putptr(void *ptr);
int	ft_printf(const char *last, ...);
int	ft_unsigned_putnbr(unsigned int x);
int	ft_find_type(const char *last, int cmpt, va_list lst);

#endif
