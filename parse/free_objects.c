/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttatsuno <ttatsuno@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:02:45 by ttatsuno          #+#    #+#             */
/*   Updated: 2026/07/21 16:20:24 by ttatsuno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_num **stack)
{
	t_num	*tmp;
	t_num	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	free_twostacks(t_num **stack_a, t_num **stack_b, int status)
{
	free_stack(stack_a);
	free_stack(stack_b);
	return (status);
}

int	free_split(char **split, int status)
{
	int	i;

	if (!split)
		return (status);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (status);
}
