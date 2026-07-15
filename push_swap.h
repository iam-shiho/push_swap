/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:27:40 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/15 16:55:21 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

//数字をまとめる構造体
typedef struct s_list
{
	struct t_num *num; //ソートする数字の連結リストを作成する
	struct bench_list	*bench; //--benchで出力する内容のまとめ
}						t_list;

//各数字に意味づけをする構造体　ソートするやつ　
typedef struct s_num
{
	int value;            // 記入されたの数値
	int index;            // 各アルゴリズムで使用する前からのインデックス
	int chunk;
	int min_index; //座標圧縮
	struct s_stack *next; // 次の要素へのポインター
	struct s_stack *prev; // 前の要素のポインター
}						t_num;

// benchの中身を保存する構造体
typedef struct bench_list
{
	double				disorder;
	// 混沌度（0.00〜1.00なので、floatかdoubleをしようする）（intだと小数点以下が表せない）%はft_printfで出力するのかな？？
	int strategy; // 使用したアルゴリズム 1:simple 2:medium 3:complex 4:adaptive
	int total_ops;  // 総操作回数

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

/*
構造体を選んだ理由
入れ込みたい要素が多いから
*/
