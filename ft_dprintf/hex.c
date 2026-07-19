/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:45:14 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 19:58:07 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_puthex(int fd, unsigned long num, const char *format)
{
	int		count;
	char	res;

	count = 0;
	if (num >= 16)
		count += ft_puthex(fd, num / 16, format);
	num = num % 16;
	if (num >= 10 && (*format == 'x' || *format == 'p'))
		res = (num - 10) + 'a';
	else if (num >= 10 && *format == 'X')
		res = (num - 10) + 'A';
	else
		res = num + '0';
	count += write(fd, &res, 1);
	return (count);
}
