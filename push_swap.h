/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:27:40 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/05 21:14:25 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>

//数字をまとめる構造体
typedef struct s_list
{
	struct num_list	 	*num;
	struct bench_list *bench;
	struct s_list	*next;
}					t_list;

//各数字に意味づけをする構造体
typedef struct num_list
{
	int				*number;//記入された数字
	int 			*level;//前からの順番（必要かわからない）
	struct num_list	 	*stuck_a;//基本aかbにいる（アドレスを指す）
	struct num_list		*stuck_b;
	struct s_list	*next; //記入された順
}					num;

//benchと打った時に出てくる詳細をまとめる構造体
typedef struct bench_list
{
	int *disorder; //記入された数字の混沌度　%はft_printfで出力するのかな？？
	char *strategy;//使用したアルゴリズム
	int *total_ops;//行動した回数の総数
	struct move_list *move;//各コマンドの詳細

}	bench;

//各動きを記録する
typedef struct move_list
{
	int sa;
	int sb;
	int ss;
	int pa;
	int pd;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}move;

#endif
