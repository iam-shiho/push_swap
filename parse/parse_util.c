/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:11:42 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 19:59:38 by swaragay         ###   ########.fr       */
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

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_num	*ft_mk_newlst(long nb)
{
	t_num	*new;

	new = malloc(sizeof(t_num));
	if (!new)
		return (NULL);
	new->value = (long)nb;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	is_duplicate(t_num *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	add_node_back(t_num **stack, t_num *new_node)
{
	t_num	*curr;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	curr = *stack;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
	new_node->prev = curr;
}
