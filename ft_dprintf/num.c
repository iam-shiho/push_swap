/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:35:25 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 19:58:11 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_num(int fd, int num)
{
	int	res;
	int	count;

	count = 0;
	if (num == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
		++count;
	}
	if (num >= 10)
		count += ft_num(fd, num / 10);
	num = num % 10;
	res = num + '0';
	count += write(fd, &res, 1);
	return (count);
}

int	ft_unnum(int fd, unsigned int num)
{
	unsigned int	res;
	int				count;

	count = 0;
	if (num >= 10)
		count += ft_unnum(fd, num / 10);
	num = num % 10;
	res = num + '0';
	count += write(fd, &res, 1);
	return (count);
}
