/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:24:10 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/07 18:25:29 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_num **stack_a, t_bench *bench)
{
	int	tmp;

	tmp = lst_pushdown(**stack_a);
	if (tmp == 0)
		return ;
	ft_printf("rra");
	++bench->rra;
}

void	rrb(t_num **stack_b, t_bench *bench)
{
	int	tmp;

	tmp = lst_pushdown(**stack_b);
	if (tmp == 0)
		return ;
	ft_printf("rrb");
	++bench->rrb;
}

void	rrr(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	ra(*stack_a, bench);
	rb(*stack_b, bench);
}
