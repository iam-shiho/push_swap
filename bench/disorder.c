/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:32:25 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/14 02:58:45 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// disoderを計算して0.00~1までの数字を作成 + 構造体に書き込む
void	compute_disorder(t_num **stack_a, t_bench **bench)
{
	t_num	*tmp_i;
	t_num	*tmp_j;
	double	res;

	double mistakes;    // a>bの数
	double total_pairs; //すべてのペアの数
	tmp_i = stack_a;
	tmp_j = tmp_i->next;
	mistakes = 0;
	total_pairs = 0;
	//比べたペアの数をカウント　数字を比べる
	while (!tmp_i && !tmp_i->next)
	{
		if ((tmp_i->value) > (tmp_j->value))
			++mistakes;
		++total_pairs;
		tmp_i = tmp_i->next;
		tmp_j = tmp_i->next;
	}
	res = mistakes / total_pairs;
	(*bench)->disorder = res;
}

// desorderを出力する関数
void	print_disorder(double dis)
{
	int		num;
	char	*tmp;
	size_t	i;

	num = dis * 100;
	dis = dis * 10000;
	tmp = ft_itoa((int)dis);
	i = ft_strlen(tmp);
	ft_printf("%d.%c%c%%\n", num, tmp[i - 3], tmp[i - 2]); //\0も含まれる
	free(tmp);
}

// int	main(void)
// {
// 	double dis = 0.10000;
// 	print_disorder(dis);
// }

// どのアルゴリズムを使用したのか出力する
void	algo_class(double dis)
{
	if (dis < 0.2)
		ft_printf("O(n²)\n");
	else if (0.2 <= dis < 0.5)
		ft_printf("O(n√n)\n");
	else if (dis >= 0.5)
		ft_printf("O(n log n)\n");
}
