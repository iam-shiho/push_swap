/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 07:33:11 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/21 14:22:16 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//最小値を先頭に持ってきてstack_bに入れ込んでいく
void	simple(t_num **stack_a, t_num **stack_b, t_bench **bench)
{
	int		i;
	t_num	*min;
	t_num	*current;

	current = *stack_a;
	i = 0;
	while (*stack_a) //配列の中身がなくなるまで
	{
		min = *stack_a;
		while (current) // minの更新　最後まで 最小値が出てくる
		{
			if (min->value > current->value)
				min = current;
			current = current->next;
		}
		move_top(stack_a, min, bench); //先頭にminを持っていく
		pb(stack_a, stack_b, bench);   // stack_bに入れ込む
	}
	while (*stack_b) // stack_bのものを移行してくる
		pa(stack_a, stack_b, bench);
}

//前から何番目かの番号をつける 一番最初に計算して-1していくのでもいい
int	put_index(t_num **stack_a)
{
	int		i;
	t_num	*current;

	current = *stack_a;
	i = 0;
	while (current)
	{
		current->index = i;
		++i;
		current = current->next;
	}
	return (i);
}

//先頭に移動させる関数
void	move_top(t_num **stack_a, t_num *min, t_bench **bench)
{
	int	i;
	int	max;

	i = 0;
	max = put_index(stack_a);
	if (min->index > max / 2)
	{
		while (min->index + i > max)
		{
			rra(stack_a, bench);
			++i;
		}
	}
	else
	{
		while (min->index > i)
		{
			ra(stack_a, bench);
			++i;
		}
	}
}
/*
"選択ソート"とは

最後までみて、そのなかで一番小さい数字(min)を見つける

・stack_aの数字をすべて比べて最小値を探す
	ex:（n-1）,(n-2)　数字の部分が確定した数字の数
・最小値を先頭持ってきてｂに移動
	・前からのインデックスをつけて最速で先頭に持ってこれるようにする。
	※常にインデックス更新できるようになったらアツい　←なってる


操作数を減らすために
indexが過半数寄りしたなら
raだけど、その以上ならrraの方が早く済みそう。indexの最大値ならrra一回で済む

最後のいっこは移動しないにしたら短縮できそう

*/
