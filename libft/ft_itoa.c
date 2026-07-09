/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 15:35:46 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 17:21:53 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_intlen(long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_putnbr(long n, char *dest, long len)
{
	dest[len] = '\0';
	if (n == 0)
	{
		dest[0] = '0';
		return (dest);
	}
	if (n < 0)
	{
		dest[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		dest[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	long	nbr;
	long	len;

	nbr = n;
	len = ft_intlen(nbr);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	return (ft_putnbr(nbr, dest, len));
}
