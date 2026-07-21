/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 19:29:07 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/21 19:27:08 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lst_swaptop(t_num **stack_a)
{
	t_num	*first;
	t_num	*second;
	t_num	*third;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	third = second->next;
	if (third != NULL)
		third->prev = first;
	first->next = third;
	second->next = first;
	*stack_a = second;
	first->prev = *stack_a;
	second->prev = NULL;
}

void	lst_movefirst(t_num **stack_a, t_num **stack_b) //aをｂに移動させる
{
	t_num	*a_first;
	t_num	*b_first;
	t_num	*a_second;

	if (!stack_a || !stack_b || !*stack_a)
		return ;
	a_first = *stack_a;
	b_first = *stack_b;
	a_second = a_first->next;
	if (a_second != NULL)
		a_second->prev = NULL;
	a_first->next = b_first;
	if (b_first != NULL)
		b_first->prev = a_first;
	*stack_a = a_second;
	*stack_b = a_first;
	if (b_first != NULL)
		b_first->prev = *stack_b;
}

void	lst_pushup(t_num **stack_a)
{
	t_num	*first;
	t_num	*second;
	t_num	*last;

	if (!stack_a || !*stack_a || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = first->next;
	last = ft_lstlast(*stack_a);
	last->next = first;
	second->prev = NULL;
	first->next = NULL;
	first->prev = last;
	*stack_a = second;
}

void	lst_pushdown(t_num **stack_a)
{
	t_num	*first;
	t_num	*last_second;
	t_num	*last;

	if (!stack_a || !*stack_a || (*stack_a)->next == NULL)
		return ;
	last = ft_lstlast(*stack_a);
	first = *stack_a;
	last_second = last->prev;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	last_second->next = NULL;
	*stack_a = last;
}
