/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:24:10 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/08 11:39:12 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_num **stack_a, t_bench *bench)
{
	if (!*stack_a || !stack_a)
		return ;
	lst_pushdown(**stack_a);
	ft_printf("rra\n");
	++bench->rra;
}

void	rrb(t_num **stack_b, t_bench *bench)
{
	if (!*stack_b || !stack_b)
		return ;
	lst_pushdown(**stack_b);
	ft_printf("rrb\n");
	++bench->rrb;
}

void	rrr(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	if (!*stack_a || !stack_a || !*stack_b || !stack_b)
		return ;
	rra(*stack_a, bench);
	rrb(*stack_b, bench);
	ft_printf("rrr\n");
	++bench->rrr;
}
