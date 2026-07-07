/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:54:45 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/07 18:24:22 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_num **stack_a, t_bench *bench)
{
	int	tmp;

	tmp = lst_swaptop(*stack_a);
	if (tmp == 0)
		return ;
	ft_printf("sa");
	++bench->sa;
}

void	sb(t_num **stack_b, t_bench *bench)
{
	int	tmp;

	tmp = lst_swaptop(*stack_b);
	if (tmp == 0)
		return ;
	ft_printf("sb");
	++bench->sb;
}

void	ss(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	sa(*stack_a, bench);
	sb(*stack_b, bench);
}
