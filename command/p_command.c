/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:06:07 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/07 18:24:19 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	int	tmp;

	tmp = lst_swapfirst(**stack_a, **stack_b);
	if (tmp == 0)
		return ;
	ft_printf("pa");
	++bench->pa;
}

void	pb(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	int	tmp;

	tmp = lst_swapfirst(**stack_b, **stack_a);
	if (tmp == 0)
		return ;
	ft_printf("pb");
	++bench->pb;
}
