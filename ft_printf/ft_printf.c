/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 08:05:24 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 17:22:10 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_conversion(const char *format, va_list args, int count)
{
	if (*format != '%')
	{
		if (*format == 'c')
			count = ft_char(va_arg(args, int));
		else if (*format == 's')
			count = ft_putstr(va_arg(args, const char *));
		else if (*format == 'p')
			count = ft_pointer(va_arg(args, void *), format);
		else if (*format == 'd' || *format == 'i')
			count = ft_num(va_arg(args, int));
		else if (*format == 'u')
			count = ft_unnum(va_arg(args, unsigned int));
		else if (*format == 'x' || *format == 'X')
			count = ft_puthex(va_arg(args, unsigned int), format);
	}
	else if (*format == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		tmp;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	tmp = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			tmp += which_conversion(format, args, count);
			if (tmp == -1)
				return (va_end(args), -1);
			count += tmp;
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}
