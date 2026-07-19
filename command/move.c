/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:29:07 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 19:55:24 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//上2つの要素を入れ替える
void	lst_swaptop(t_num **stack_a)
{
	t_num	*first;
	t_num	*second;
	t_num	*third;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;       // stack_aの一番先頭のアドレスを代入
	second = first->next;   //二番目の要素の構造体のアドレスを代入
	third = second->next;   // 3つ目の要素のアドレスを代入
	first->next = third;    //最初の構造体の次を3番目の構造体にする　1→3
	second->next = first;   //二番目の構造体の次を一番目の構造体にする 2→1
	*stack_a = second;      //先頭アドレスを二番目の構造体にする 2→1→3
	first->prev = *stack_a; //一個前のアドレスの更新
	third->prev = first;    // 3つ目の一個まえのアドレスを更新
}

// stack_aの先頭をstack_bの先頭に追加する
void	lst_movefirst(t_num **stack_a, t_num **stack_b)
{
	t_num	*a_first;
	t_num	*b_first;
	t_num	*a_second;

	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	a_first = *stack_a; // 一番先頭のアドレスを代入
	b_first = *stack_b;
	a_second = a_first->next; // 二番目のアドレスを保持
	a_first->next = b_first;  // 1つ次のアドレスを代入　a→b b→a
	b_first->prev = a_first;
	*stack_a = a_second; //先頭アドレスの更新
	*stack_b = a_first;
	a_second->prev = NULL; //二個目の1つ前のアドレスを更新
	b_first->prev = *stack_b;
}

//すべての要素を1つ上にシフトする　前から1つずつインデックスをつけるなら他に作業を付け足さないとかも
void	lst_pushup(t_num **stack_a)
{
	t_num	*first;
	t_num	*second;
	t_num	*last;

	if (!stack_a || !*stack_a)
		return ;
	first = *stack_a; //各変数にアドレスを代入する
	second = first->next;
	last = ft_lstlast(*stack_a);
	last->next = first; //一番上の構造体を下にシフトする
	second->prev = NULL; //二番目の構造体が先頭になるため前のアドレスにNULLを代入する
	first->next = NULL; //最後になったため次の構造体はないためNULLを代入する
	last->next = first; //元々最後だった構造体のあとに一個構造体が追加されたからアドレスを代入
	first->prev = last; // 前のアドレスを更新
	*stack_a = second; //先頭アドレスの更新
}

//すべての要素を1つ下にシフトする
void	lst_pushdown(t_num **stack_a)
{
	t_num	*first;
	t_num	*last_second;
	t_num	*last;

	if (!stack_a || !*stack_a)
		return ;
	last = ft_lstlast(*stack_a); //各アドレスを保持
	first = *stack_a;
	last_second = last->prev;
	last->next = first;       //一番目の次を元一番目に変更
	last->prev = NULL;        //先頭になったから一個前のアドレスをNULL
	first->prev = last;       //一個前に追加されたからアドレスを追加
	last_second->next = NULL; //最後の構造体なのでNULL
	*stack_a = last;          //先頭アドレスを更新
}
