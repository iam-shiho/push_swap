/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 07:33:08 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 22:31:26 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	medium(t_num **stack_a, t_num **stack_b, t_bench **bench)
{
	int		i;
	int		j;
	t_num	*max;
	t_num	*current;

	current = *stack_b;
	i = 0;
	j = 0;
	move_b(stack_a, stack_b, bench);
	while (*stack_b) //最大値を見つけてaに移動させる
	{
		while (current) //最大値を見つけてaに移動
		{
			if (max->value < current->value)
				max = current;
			current = current->next;
		}
		move_top(stack_a, max, bench);
		pa(stack_a, stack_b, bench);
	}
}

/*
・探索する数を√ｎ個ずつに分ける　123/456/789/ みたいな！
・0~分けた数字まで　該当しかものはｂにいれていく
	・ｂに送る際に偶数は上、奇数は下など操作してVの字ができるようにしていく
		降順よりも、はやく先頭に数字を持っていける
*/

// √ｎをもとめる
int	compute_chunksize(t_num **stack_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*stack_a);
	while (size <= i * i) //√ｎを求める
		++i;
	return (i);
}

void	move_b(t_num **stack_a, t_num **stack_b, t_bench **bench)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*stack_a) // sizeごとにまわして、数字を比べる
	{
		while (*stack_a) // sizeごとにその中の数字を探して探索する
		{
			if ((*stack_a)->value < compute_chunksize(stack_a) * i)
			{
				pb(stack_a, stack_b, bench);
				if (j % 2 == 0)
					rb(stack_b, bench);
				++j;
			}
			else
				ra(stack_a, bench);
		}
		++i;
	}
}
