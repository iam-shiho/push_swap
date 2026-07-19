/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 13:51:11 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 19:59:30 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	coordinate_compression(t_num *stack_a)
{
	t_num	*current;
	t_num	*compare;
	int		count;

	current = stack_a;
	while (current)
	{
		count = 0;
		compare = stack_a;
		while (compare)
		{
			if (compare->value < current->value)
				count++;
			compare = (t_num *)compare->next;
		}
		current->min_index = count;
		current = (t_num *)current->next;
	}
}
