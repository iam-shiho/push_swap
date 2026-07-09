/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:20:47 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 17:21:55 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//構造体リストの最後のアドレスをリターン
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
