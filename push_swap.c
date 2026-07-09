/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:19:45 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/10 05:27:41 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//各アルゴリズムに振り分けてソートする関数　voidでいいのか不明
void	choose_algorithm(t_num **stack_a, double disorder, t_bench **bench,
		int adaptive)
{
	if (adaptive == 1)
	{
		//自作アルゴリズム関数に入る
		(*bench)->strategy = ft_strdup("アルゴリズム名");
	}
	//指定がない場合はdisorderで分類
	if (disorder < 0.2)
	{
		//アルゴリズム関数に入る
		(*bench)->strategy = ft_strdup("アルゴリズム名");
	}
	else if (0.2 <= disorder < 0.5)
	{
		//アルゴリズム関数に入る
		(*bench)->strategy = ft_strdup("アルゴリズム名");
	}
	else if (disorder >= 0.5)
	{
		//アルゴリズム関数に入る
		(*bench)->strategy = ft_strdup("アルゴリズム名");
	}
}

// stack_aを受け取ってソートするまでの関数（いるかわからないけど作成する。型はvoidでいいのかわからん！！） benchの中身も追加する
int	main(int argc, char **argv)
{
	t_bench	**bench;
	t_list	**lst;
	int		adaptive;
	double	dis;

	/*各構造体の中身が詰められた上で*/

	//手打ちでdisorderを指定する
	if (argc == "--simple")
		dis = 0.1;
	else if (argc == "--medium")
		dis = 0.3;
	else if (argc == "--complex")
		dis = 0.6;
	else if (argc == "--adaptive")
		adaptive = 1;
	else
		dis = compute_disorder((*lst)->num, *bench); //指定されていないときは計算結果を代入
	compute_disorder((*lst)->num, *bench); //フラグが指定されている場合disorderの計算ができていないからどっかで計算したい
	choose_algorithm((*lst)->num, dis, *bench, adaptive);
	if (argc == "--bench") //benchを出力する
		print_bench(*bench);
}

/*
アルゴリズムを手動で選択した際は、連結リストを作ったあと対応するdisorderをわたして、benchのためにdisorderを計算するけどこの関数のdisorderは手入力にする
*/
