/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 07:33:11 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/13 19:11:30 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//最小値を先頭に持ってきてstack_bに入れ込んでいく
void	simple(t_num **stack_a, t_num **stack_b, t_num **bench)
{
	int		i;
	t_num	*min;

	i = 0;
	while (stack_a) //配列の中身がなくなるまで
	{
		min = *stack_a;
		while (*stack_a) // minの更新　最後まで 最小値が出てくる
		{
			if (min->value > (*stack_a)->value)
				min = *stack_a;
			stack_a = (*stack_a)->next;
		}
		move_top(*stack_a, min, *bench); //先頭にminを持っていく
		pb(*stack_a, *stack_b, *bench);  // stack_bに入れ込む
	}
	while (*stack_b) // stack_bのものを移行してくる
		pa(*stack_a, *stack_b, *bench);
}

//前から何番目かの番号をつける 一番最初に計算して-1していくのでもいい
int	put_index(t_num **stack_a)
{
	int	i;

	i = 1;
	while (*stack_a)
	{
		(*stack_a)->index = i;
		++i;
		stack_a = (*stack_a)->next;
	}
	return (i);
}

//先頭に移動させる関数
void	move_top(t_num **stack_a, t_num *min, t_num **bench)
{
	int	i;
	int	max;

	i = 0;
	max = put_index(*stack_a);
	if (min->index > max / 2)
	{
		while (min->index + i > max + 1)
		{
			rra(*stack_a, *bench);
			++i;
		}
	}
	else
	{
		while (min->index > i)
		{
			ra(*stack_a, *bench);
			++i;
		}
	}
}
/*
最後までみて、そのなかで一番小さい数字を見つける


小さい数字を先頭持ってきてｂに移動
前からのインデックスをつけて最速で先頭に持ってこれるようにする。
※常にインデックス更新できるようになったらアツい
→　比べてる数字が大きくなるまで繰り返す
比べた数字の頬が大きい場合はそこでやめて次の数字へ


操作数を減らすために
indexが過半数寄りしたなら
raだけど、その以上ならrraの方が早く済みそう。indexの最大値ならrra一回で済む

*/
