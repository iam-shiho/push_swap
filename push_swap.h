/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:27:40 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/07 14:00:53 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

//数字をまとめる構造体
typedef struct s_list
{
	struct num_list		*num;
	struct bench_list	*bench;
	struct s_list		*next;
}						t_list;

//各数字に意味づけをする構造体　ソートするやつ　
typedef struct s_num
{
	int value;            // 記入されたの数値
	int index;            // 小さい順のインデックス０〜
	struct s_stack *next; // 次の要素へのポインター
	struct s_stack *prev; // 前の要素のポインター
}						t_num;

/*
Bは関数内で実装する？
*/

// benchの中身を保存する構造体
typedef struct bench_list
{
	double disorder;
		// 混沌度（0.00〜1.00なので、floatかdoubleをしようする）（intだと小数点以下が表せない）%はft_printfで出力するのかな？？
	char *strategy;  // 使用したアルゴリズム名
	int total_ops;   // 総操作回数

	// 各コマンドのカウンター
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_bench;

#endif
