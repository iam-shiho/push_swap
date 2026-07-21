/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 07:33:08 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/21 19:52:48 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	medium(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	int		i;
	int		j;
	t_num	*max;
	t_num	*current;

	i = 0;
	j = 0;
	move_b(stack_a, stack_b, bench);
	while (*stack_b)
	{
		max = *stack_b;
		current = max->next;
		while (current)
		{
			if (max->value < current->value)
				max = current;
			current = current->next;
		}
		move_top(stack_b, max, bench);
		pa(stack_a, stack_b, bench);
	}
}

int	compute_chunksize(t_num *stack_a)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(stack_a);
	while (size >= i * i)
		++i;
	return (i);
}

void	move_b(t_num **stack_a, t_num **stack_b, t_bench *bench)
{
	int	i;
	int j;
	int	chunk_size;

	j = 0;
	chunk_size = compute_chunksize(*stack_a);
	i = 1;
	while (*stack_a)
	{
		if ((*stack_a)->min_index < chunk_size * i)
		{
			pb(stack_a, stack_b, bench);
			if ((*stack_b)->next && j % 2 == 0)
				rb(stack_b, bench);
		}
		else
			ra(stack_a, bench);
		if (ft_lstsize(*stack_b) >= chunk_size * i)
			++i;
	}
}
