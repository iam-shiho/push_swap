/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:27:34 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/10 13:50:04 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// benchの中身をプリントする関数 --benchが来たときに稼働するようにする
void	print_bench(t_bench *bench)
{
	ft_printf("[bench] disorder: ");
	print_disorder(bench->disorder);
	if (bench->strategy == '1')
		ft_printf("[bench] strategy: Simple / O(n²)\n");
	else if (bench->strategy == '2')
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	else if (bench->strategy == '3')
		ft_printf("[bench] strategy: Complex / O(n log n)\n");
	else if (bench->strategy == '4')
	{
		ft_printf("[bench] strategy: Adaptive / ");
		algo_class(bench->disorder);
	}
	ft_printf("[bench] total_ops: %d\n", bench->total_ops);
	ft_printf("[bench]  sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->sa,
		bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench]  ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
