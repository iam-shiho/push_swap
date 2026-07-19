/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 07:33:03 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 21:45:05 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//各アルゴリズムに振り分けてソートする関数　voidでいいのか不明
void	adaptive(t_num **stack_a, t_num **stack_b, t_bench **bench)
{
	if ((*bench)->disorder < 0.2)
		simple(stack_a, stack_b, bench);
	else if (0.2 <= (*bench)->disorder < 0.5)
		medium(stack_a, stack_b, bench);
	else if ((*bench)->disorder >= 0.5)
		complex(stack_a, stack_b, bench);
}
