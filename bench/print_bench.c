/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:27:34 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 21:30:04 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// benchの中身をプリントする関数 --benchが来たときに稼働するようにする
void	print_bench(t_bench *bench)
{
	ft_dprintf(2, "[bench] disorder: ");
	print_disorder(bench->disorder);
	if (bench->strategy == '1')
		ft_dprintf(2, "[bench] strategy: Simple / O(n²)\n");
	else if (bench->strategy == '2')
		ft_dprintf(2, "[bench] strategy: Medium / O(n√n)\n");
	else if (bench->strategy == '3')
		ft_dprintf(2, "[bench] strategy: Complex / O(n log n)\n");
	else if (bench->strategy == '0')
	{
		ft_dprintf(2, "[bench] strategy: Adaptive / ");
		algo_class(bench->disorder);
	}
	ft_dprintf(2, "[bench] total_ops: %d\n", bench->total_ops);
	ft_dprintf(2, "[bench]  sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->sa,
		bench->sb, bench->ss, bench->pa, bench->pb);
	ft_dprintf(2, "[bench]  ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
