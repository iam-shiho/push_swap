/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:09:54 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/21 18:00:39 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_num **stack_a, t_bench *bench)
{
	if (!stack_a || !*stack_a || (*stack_a)->next == NULL)
		return ;
	lst_pushup(stack_a);
	ft_dprintf(1, "ra\n");
	++bench->ra;
	++bench->total_ops;
}

void	rb(t_num **stack_b, t_bench *bench)
{
	if (!stack_b || !*stack_b || (*stack_b)->next == NULL)
		return ;
	lst_pushup(stack_b);
	ft_dprintf(1, "rb\n");
	++bench->rb;
	++bench->total_ops;
}

void	rr(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b
		|| (*stack_a)->next == NULL || (*stack_b)->next == NULL)
		return ;
	lst_pushup(stack_a);
	lst_pushup(stack_b);
	ft_dprintf(1, "rr\n");
	++bench->rr;
	++bench->total_ops;
}
