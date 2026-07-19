/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 07:33:06 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 19:54:23 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	complex(t_num **stack_a, t_num **stack_b, t_num **bench)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = count_bitsize(ft_lstsize(stack_a));
	while (*stack_a || i < size) //桁数分回る
	{
		while (*stack_a || j < size) // bitが0のときにｂに移動させる　
		{
			if ((((*stack_a)->min_index >> j) & 1) == 0)
				// bitをi分シフトする→型抜く→それが０だったばあいbにいく
				pb(*stack_a, *stack_b, *bench);
			else
				ra(*stack_a, *bench);
			++j;
		}
		while (*stack_b)
			pa(*stack_a, *stack_b, *bench);
		++i;
	}
}

int	count_bitsize(int num)
{
	int	i;

	while (num) //２進数の桁数を数える
	{
		num = num / 2;
		++i;
	}
	return (i);
}
