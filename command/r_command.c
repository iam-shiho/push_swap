/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:09:54 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/08 11:47:52 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_num **stack_a, t_bench *bench)
{
	if (!*stack_a || !stack_a)
		return ;
	lst_pushup(**stack_a);
	ft_printf("ra\n");
	++bench->ra;
}

void	rb(t_num **stack_b, t_bench *bench)
{
	if (!*stack_b || !stack_b)
		return ;
	lst_pushup(**stack_b);
	ft_printf("rb\n");
	++bench->rb;
}

void	rr(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	if (!*stack_a || !stack_a || !*stack_b || !stack_b)
		return ;
	ra(*stack_a, bench);
	rb(*stack_b, bench);
	ft_printf("rr\n");
	++bench->rr;
}
// if文の条件文を足して、実行するかしないか判断する
