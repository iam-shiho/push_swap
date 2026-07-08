/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:06:07 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/08 16:59:46 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	lst_movefirst(**stack_a, **stack_b);
	ft_printf("pa\n");
	++bench->pa;
}

void	pb(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	lst_movefirst(**stack_b, **stack_a);
	ft_printf("pb\n");
	++bench->pb;
}
