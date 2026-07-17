/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:45:14 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 20:56:18 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "ft_printf.h"

int	ft_puthex(unsigned long num, const char *format)
{
	int		count;
	char	res;

	count = 0;
	if (num >= 16)
		count += ft_puthex(num / 16, format);
	num = num % 16;
	if (num >= 10 && (*format == 'x' || *format == 'p'))
		res = (num - 10) + 'a';
	else if (num >= 10 && *format == 'X')
		res = (num - 10) + 'A';
	else
		res = num + '0';
	count += write(1, &res, 1);
	return (count);
}
