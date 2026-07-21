/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 07:33:11 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/21 19:29:48 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	t_num	*min;
	t_num	*current;

	while (*stack_a)
	{
		put_index(stack_a);
		min = *stack_a;
		current = min->next;
		while (current)
		{
			if (min->value > current->value)
				min = current;
			current = current->next;
		}
		move_top(stack_a, min, bench);
		pb(stack_a, stack_b, bench);
	}
	while (*stack_b)
		pa(stack_a, stack_b, bench);
}

void	put_index(t_num **stack_a)
{
	int		i;
	t_num	*current;

	current = *stack_a;
	i = 0;
	while (current)
	{
		current->index = i;
		++i;
		current = current->next;
	}
}

void	move_top(t_num **stack_a, t_num *min, t_bench *bench)
{
	int	i;
	int	max;

	i = 0;
	max = ft_lstsize(*stack_a);
	if (min->index > max / 2)
	{
		while (i < max - min->index)
		{
			rra(stack_a, bench);
			++i;
		}
	}
	else
	{
		while (min->index > i)
		{
			ra(stack_a, bench);
			++i;
		}
	}
}
