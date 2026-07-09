/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 02:27:34 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/10 02:33:09 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//benchの中身をプリントする関数 --benchが来たときの信号がわかるような引数にする
void print_bench(int i, t_bench *bench)
{
	ft_printf("[bench] disorder: ");
	print_disorder(bench->disorder);
	
}
