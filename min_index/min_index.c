/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 13:51:11 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/13 18:39:08 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//最小値からどのぐらいはなれているのか indexをつける
void	min_index(t_num **stack_a)
{
	t_num	*min;
	int		i;
	int		j;

	min = *stack_a;
	i = 0;
	j = 0;
	while (!*stack_a)
	{
		while (!*stack_a) // minを見つける
		{
			if (min->value + j > (*stack_a)->value) 
			{
				min = *stack_a;
				j = 0;
			}
			//&& min_index == 0 まだ数字が当てはめられてない
			stack_a = (*stack_a)->next;
		}
		min->min_index = i;
		++i;
		++j;
	}
}

/*
minを見つける
indexをつける
繰り返し

indexを付与済み後に次のminを探すいい手段が見当たらず、一個ずつ数字を足していくことにした。ただ数の差がすごいとその分繰り返さなきゃだから大変

*/
