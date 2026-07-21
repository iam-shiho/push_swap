/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 07:33:06 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/21 16:31:04 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	complex(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = count_bitsize(ft_lstsize(*stack_a));
	while (*stack_a || i < size)
	{
		while (*stack_a || j < size)
		{
			if ((((*stack_a)->min_index >> j) & 1) == 0)
				pb(stack_a, stack_b, bench);
			else
				ra(stack_a, bench);
			++j;
		}
		while (*stack_b)
			pa(stack_a, stack_b, bench);
		++i;
	}
}

int	count_bitsize(int num)
{
	int	i;

	i = 0;
	while (num)
	{
		num = num / 2;
		++i;
	}
	return (i);
}
