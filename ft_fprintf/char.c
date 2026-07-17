/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 08:47:25 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/17 21:14:24 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "ft_printf.h"

int	ft_char(int c)
{
	unsigned char	cc;

	cc = (unsigned char)c;
	return (write(1, &cc, 1));
}

int	ft_putstr(const char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	while (s[count] != '\0')
	{
		write(1, &s[count], 1);
		++count;
	}
	return (count);
}

int	ft_pointer(void *p, const char *format)
{
	int				count;
	unsigned long	point;

	if (!p)
		return (write(1, "(nil)", 5));
	count = 0;
	point = (unsigned long)p;
	count += write(1, "0x", 2);
	count += ft_puthex(point, format);
	return (count);
}
