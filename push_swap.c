/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:19:45 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 16:29:23 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
