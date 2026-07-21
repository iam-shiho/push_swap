/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:53:03 by ttatsuno          #+#    #+#             */
/*   Updated: 2026/07/21 16:30:46 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	str1[] = "Hello 42!";
// 	char	str2[] = "Hello 42!";
//
// 	bzero(str1, 2);
// 	ft_bzero(str2, 2);
//
// 	printf("printf: %d, %d, %d...\n", str1[0], str1[1], str1[2]);
// 	printf("ft_printf: %d, %d, %d...\n", str2[0], str2[1], str2[2]);
// 	return (0);
// }
