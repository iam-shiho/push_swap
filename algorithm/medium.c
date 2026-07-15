/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 07:33:08 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/15 18:33:48 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium(t_num **stack_a, t_num **stack_b, t_num **bench)
{
	int		i;
	t_num	*min;

	i = 0;
	chunk_number(*stack_a);
	//チャンクごとにソート
	while (*stack_a) // chunkごとにソートする
	{
		while ()
		{
			while (*stack_a || (*stack_a)->chunk == i) // chunkごとにソートする
			{
				min = *stack_a;
				if (min->value > (*stack_a)->value)
					min = *stack_a;
			}
			ra(*min, *stack_b, *bench);
		}
		++i;
	}
	while (*stack_b) // ソートしながらstack_bのものを移行してくる
	{
		pa(*stack_a, *stack_b, *bench);
	}
}

/*
・n個のチャンクにわける
	・インデックスをつける
・ソートする
	・stack_bにchunk毎入れていく
		・stack_bを降順に整頓する
・stack_aに入れ直す
・チャンクの[i]ごとにくらべていく
	・stack_bにチャンクの中身が移動されたときにそのチャンクが次のインデックスにかわる
・stack_aに入れ直す
*/

// chunkに分けるのとチャンクごとのインデックスをつける
void	chunk_number(t_num **stack_a)
{
	int	i;
	int	j;
	int	size;

	size = ft_lstsize(stack_a) / 5; //チャンクの数はここで変える
	while (*stack_a || i < 5)
	{
		j = 0;
		while (*stack_a || j < size)
		{
			(*stack_a)->chunk = i;
			(*stack_a)->index = j;
			stack_a = (*stack_a)->next;
			++j;
		}
		++i;
	}
}
