/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:29:07 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/07 15:08:04 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//上2つの要素を入れ替える
void	lst_swaptop(struct t_num **stack_a)
{
	t_num	*first;
	t_num	*second;
	t_num	*third;

	if (!*stack_a || !stack_a) // (*stack_a)->next == NULL
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

// abの最上要素を入れ替える
void	lst_swapfirst(struct t_num **stack_a, struct t_num **stack_b)
{
	t_num	*a_first;
	t_num	*b_first;
	t_num	*a_second;
	t_num	*b_second;

	if (!*stack_a || !stack_a || !*stack_b || !stack_b)
		// (*stack_a)->next == NULL
		return ;
	a_first = *stack_a; // 一番先頭のアドレスを代入
	b_first = *stack_b;
	a_second = a_first->next; // 二番目のアドレスを保持
	b_second = b_first->next;
	a_first->next = b_second; // 1つ次のアドレスを代入　a→b b→a
	b_first->next = a_second;
	*stack_a = b_first; //先頭アドレスの更新
	*stack_b = a_first;
	a_second->prev = *stack_a; //二個目の1つ前のアドレスを更新
	b_second->prev = *stack_b;
}

//すべての要素を1つ上にシフトする
void	lst_pushup(struct t_num **stack_a)
{
	t_num	*a_first;
	t_num	*b_first;
	t_num	*a_second;
	t_num	*b_second;

	if (!*stack_a || !stack_a)
		// (*stack_a)->next == NULL
		return ;
	//一番先頭を先に最後に移動させる？
	while (stack_a != NULL)
	{
		
	}
}
