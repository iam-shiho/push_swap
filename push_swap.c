/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:32:25 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 15:00:58 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// disoderを計算して0.00~1までの数字を出力
double	compute_disorder(t_num **stack_a)
{
	t_num	*tmp_i;
	t_num	*tmp_j;

	double mistakes;    // a>bの数
	double total_pairs; //すべてのペアの数
	tmp_i = stack_a;
	tmp_j = tmp_i->next;
	mistakes = 0;
	total_pairs = 0;
	//比べたペアの数をカウント　数字を比べる
	while (!tmp_i && !tmp_i->next)
	{
		if ((tmp_i->value) > (tmp_j->value))
			++mistakes;
		++total_pairs;
		tmp_i = tmp_i->next;
		tmp_j = tmp_i->next;
	}
	return (mistakes / total_pairs);
}

//各アルゴリズムに振り分けてソートする関数
void push_swap(t_num **stack_a, double disorder, t_bench *bench)
{
	if(disorder < 0.2)
	{
		//アルゴリズム関数に入る
		bench->strategy = "アルゴリズム名"; //mallocするのか？
	}

}

/*
アルゴリズムを手動で選択した際は、連結リストを作ったあと対応するdisorderをわたして、benchのためにdisorderを計算するけどこの関数のdisorderは手入力にする
*/
