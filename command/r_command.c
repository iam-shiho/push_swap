/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:09:54 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/07 18:26:29 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_num **stack_a, t_bench *bench)
{
	int	tmp;

	tmp = lst_pushup(**stack_a);
	if (tmp == 0)
		return ;
	ft_printf("ra");
	++bench->ra;
}

void	rb(t_num **stack_b, t_bench *bench)
{
	int	tmp;

	tmp = lst_pushup(**stack_b);
	if (tmp == 0)
		return ;
	ft_printf("rb");
	++bench->rb;
}

void	rr(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	int tmp;
	tmp = ra(*stack_a, bench);
	if (tmp == 1)
	rb(*stack_b, bench);
}
