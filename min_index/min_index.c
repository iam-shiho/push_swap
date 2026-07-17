/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 13:51:11 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/16 22:05:01 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//最小値からどのぐらいはなれているのか indexをつける
void	min_index(t_num **stack_a)
{
	t_num	*copy;
	int		i;
	int		j;
	int size;

	size = count_bitsize(max_value(stack_a));

	copy = *stack_a;
	while (copy || i < size) //桁数分回る
	{
		while (copy || j < size) // bitが0のときにｂに移動させる　
		{
			if ((((*stack_a)->min_index >> j) & 1) == 0)
				// bitをi分シフトする→型抜く→それが０だったばあいbにいく
				//bに移動させる
			else

			++j;
		}
		while (*stack_b)
			pa(*stack_a, *stack_b, *bench);
		++i;
	}
}

int	max_value(t_num *stack_a)
{
	int	max;

	while (stack_a)
	{
		if (stack_a->value > max)
			max = stack_a->value;
		stack_a = stack_a->next;
	}
	return (max);
}

/*

*/
