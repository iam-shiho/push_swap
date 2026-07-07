/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:29:07 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/05 21:35:42 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//使用回数をreturnするべきか否か
void	swap(struct *number)
{
	t_list	*first;
	t_list	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL || stack_a == NULL)
		return (0);
	first = stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa", 2);
	return (1);
}

int	pa_move(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL || stack_a == NULL)
		return (0);
	first = stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa", 2);
	return (1);
}
