/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:35:25 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/07 18:51:23 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	ft_num(int num)
{
	int	res;
	int	count;

	count = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		++count;
	}
	if (num >= 10)
		count += ft_num(num / 10);
	num = num % 10;
	res = num + '0';
	count += write(1, &res, 1);
	return (count);
}

int	ft_unnum(unsigned int num)
{
	unsigned int	res;
	int				count;

	count = 0;
	if (num >= 10)
		count += ft_unnum(num / 10);
	num = num % 10;
	res = num + '0';
	count += write(1, &res, 1);
	return (count);
}
