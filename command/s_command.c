/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:54:45 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/08 11:38:48 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_num **stack_a, t_bench *bench)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	lst_swaptop(*stack_a);
	ft_printf("sa\n");
	++bench->sa;
}

void	sb(t_num **stack_b, t_bench *bench)
{
	if (!*stack_b || !stack_b || !(*stack_b)->next)
		return ;
	lst_swaptop(*stack_b);
	ft_printf("sb\n");
	++bench->sb;
}

void	ss(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	if (!*stack_a || !stack_a || !(*stack_a)->next || !*stack_b || !stack_b
		|| !(*stack_b)->next)
		return ;
	sa(*stack_a, bench);
	sb(*stack_b, bench);
	ft_printf("ss\n");
	++bench->ss;
}
