/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:24:10 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 16:13:13 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_num **stack_a, t_bench **bench)
{
	if (!stack_a || !*stack_a)
		return ;
	lst_pushdown(**stack_a);
	ft_dprintf(1, "rra\n");
	++(*bench)->rra;
	++(*bench)->total_ops;
}

void	rrb(t_num **stack_b, t_bench **bench)
{
	if (!stack_b || !*stack_b)
		return ;
	lst_pushdown(**stack_b);
	ft_dprintf(1, "rrb\n");
	++(*bench)->rrb;
	++(*bench)->total_ops;
}

void	rrr(t_num **stack_a, t_num **stack_b, t_bench **bench)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	lst_pushdown(**stack_a);
	lst_pushdown(**stack_b);
	ft_dprintf(1, "rrr\n");
	++(*bench)->rrr;
	++(*bench)->total_ops;
}
