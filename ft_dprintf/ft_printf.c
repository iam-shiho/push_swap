/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 08:05:24 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 15:56:29 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "ft_dprintf.h"

int	which_conversion(int fd, const char *format, va_list args, int count)
{
	if (*format != '%')
	{
		if (*format == 'c')
			count = ft_char(fd, va_arg(args, int));
		else if (*format == 's')
			count = ft_putstr(fd, va_arg(args, const char *));
		else if (*format == 'p')
			count = ft_pointer(fd, va_arg(args, void *), format);
		else if (*format == 'd' || *format == 'i')
			count = ft_num(fd, va_arg(args, int));
		else if (*format == 'u')
			count = ft_unnum(fd, va_arg(args, unsigned int));
		else if (*format == 'x' || *format == 'X')
			count = ft_puthex(fd, va_arg(args, unsigned int), format);
	}
	else if (*format == '%')
		count = write(fd, "%", 1);
	return (count);
}

int	ft_ddprintf(int fd, const char *format, ...)
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
			tmp += which_conversion(fd, format, args, count);
			if (tmp == -1)
				return (va_end(args), -1);
			count += tmp;
		}
		else
			count += write(fd, format, 1);
		++format;
	}
	return (va_end(args), count);
}

/*
１つ目の引数に出力先が記入される

*/
