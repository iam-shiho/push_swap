/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 08:47:25 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 19:56:09 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_char(int fd, int c)
{
	unsigned char	cc;

	cc = (unsigned char)c;
	return (write(fd, &cc, 1));
}

int	ft_putstr(int fd, const char *s)
{
	int	count;

	if (!s)
		return (write(fd, "(null)", 6));
	count = 0;
	while (s[count] != '\0')
	{
		write(fd, &s[count], 1);
		++count;
	}
	return (count);
}

int	ft_pointer(int fd, void *p, const char *format)
{
	int				count;
	unsigned long	point;

	if (!p)
		return (write(fd, "(nil)", 5));
	count = 0;
	point = (unsigned long)p;
	count += write(fd, "0x", 2);
	count += ft_puthex(fd, point, format);
	return (count);
}
