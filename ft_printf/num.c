/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 12:35:25 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 15:52:23 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_putdouble(double num)
{
	int	tmp;
	char	*res;
	size_t i;

	tmp = num * 10000;
	res = ft_itoa(tmp);
	i = ft_strlen(res);
	write(1,&res[i-1],1);
	write(1,&res[i-2],1);
	write(1, ".", 1);
	res = ft_free(res);
	tmp = num / 100;
	write(1, , );
}


/*
全体の文字列と小数点以下の文字数がわかればそこから引き算してwriteすればいいのかな

・×10000 する
・した2つを出力
・小数点を出力(".")
・割る100して、int型にキャストして出力
*/
