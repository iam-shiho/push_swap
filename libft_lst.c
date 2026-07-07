/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 15:28:37 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/07 20:57:37 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//構造体リストの最後
t_num	*ft_lstlast(t_num **stack_a)
{
	if (!stack_a || !*stack_a)
		return (NULL);
	while ((*stack_a)->next != NULL)
	{
		stack_a = (*stack_a)->next;
	}
	return (stack_a);
}

//後ろに構造体を1つ付け足す
void	ft_lstadd_back(t_num **stack_a, t_num *new)
{
	if (!stack_a || !new)
		return ;
	if (*stack_a == NULL)
	{
		*stack_a = new;
		return ;
	}
	ft_lstlast(*stack_a)->next = new;
}

//前に構造体を1つ付け足す
void	ft_lstadd_front(t_num **stack_a, t_num *new)
{
	if (!stack_a || !new)
		return ;
	new->next = *stack_a;
	*stack_a = new;
}
