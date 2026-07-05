/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:27:40 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/05 21:03:26 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>

typedef struct s_list
{
	struct num_list	 	*stuck_a;
	struct num_list		*stuck_b;
	struct bench_list *bench;
	struct s_list	*next;
}					t_list;


typedef struct num_list
{
	int				*number;
	int 			*level;
	struct s_list	*next;
}					num;


typedef struct bench_list
{
	int *disorder; //
	char *strategy;
	int *total_ops;
	struct move_list *move;

}	bench;

//各動きを記録する
typedef struct move_list
{
	int sa;
	int sb;
	int ss;
	int pa;
	int pd;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}move;

#endif
