/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttatsuno <ttatsuno@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:53:48 by ttatsuno          #+#    #+#             */
/*   Updated: 2026/07/21 16:57:57 by ttatsuno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *nptr)
{
	int		sign;
	long	result;
	long	limit;

	sign = 1;
	result = 0;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	limit = INT_MAX;
	if (sign < 0)
		limit = -(long)INT_MIN;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (result > (limit - (*nptr - '0')) / 10)
			return ((limit + 1) * sign);
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

int	is_valid_num_str(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
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
