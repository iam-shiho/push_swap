/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:54:45 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 16:13:26 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_num **stack_a, t_bench **bench)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	lst_swaptop(*stack_a);
	ft_dprintf(1, "sa\n");
	++(*bench)->sa;
	++(*bench)->total_ops;
}

void	sb(t_num **stack_b, t_bench **bench)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	lst_swaptop(*stack_b);
	ft_dprintf(1, "sb\n");
	++(*bench)->sb;
	++(*bench)->total_ops;
}

void	ss(t_num **stack_a, t_num **stack_b, t_bench **bench)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b || !(*stack_a)->next
		|| !(*stack_b)->next)
		return ;
	lst_swaptop(*stack_a);
	lst_swaptop(*stack_b);
	ft_dprintf(1, "ss\n");
	++(*bench)->ss;
	++(*bench)->total_ops;
}
