/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:35:25 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 20:56:21 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "ft_printf.h"

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

// desorderを出力する関数
int	res_disorder(double dis)
{
	int		count;
	char	*tmp;
	size_t	i;

	count = 0;
	//整数部分を入れる
	dis = dis * 100;
	count += write(1, ft_itoa((int)dis), 2);
	//小数点を入れる
	count += write(1, ".", 1);
	dis = dis * 100;
	tmp = ft_itoa((int)dis);
	i = ft_strlen(tmp);
	count += write(1, &tmp[i - 3], 1);
	count += write(1, &tmp[i - 2], 1);
	count += write(1, "%", 1);
	return (count);
}
