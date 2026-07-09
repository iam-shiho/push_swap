/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:19:45 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 17:21:45 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//各アルゴリズムに振り分けてソートする関数　voidでいいのか不明
void	choose_algorithm(t_num **stack_a, double disorder, t_bench *bench,
		int adaptive)
{
	if (adaptive == 1)
	{
		//自作アルゴリズム関数に入る
		bench->strategy = ft_strdup("アルゴリズム名");
	}
	//指定がない場合はdisorderで分類
	if (disorder < 0.2)
	{
		//アルゴリズム関数に入る
		bench->strategy = ft_strdup("アルゴリズム名");
	}
	else if (0.2 <= disorder < 0.5)
	{
		//アルゴリズム関数に入る
		bench->strategy = ft_strdup("アルゴリズム名");
	}
	else if (disorder >= 0.5)
	{
		//アルゴリズム関数に入る
		bench->strategy = ft_strdup("アルゴリズム名");
	}
}

/*
アルゴリズムを手動で選択した際は、連結リストを作ったあと対応するdisorderをわたして、benchのためにdisorderを計算するけどこの関数のdisorderは手入力にする
*/
