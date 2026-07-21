/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:32:25 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/21 17:00:53 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	compute_disorder(t_num *stack_a, t_bench *bench)
{
	t_num	*tmp_i;
	t_num	*tmp_j;
	double	res;
	double	mistakes;
	double	total_pairs;

	tmp_i = stack_a;
	tmp_j = tmp_i->next;
	mistakes = 0;
	total_pairs = 0;
	while (!tmp_i && !tmp_i->next)
	{
		if ((tmp_i->value) > (tmp_j->value))
			++mistakes;
		++total_pairs;
		tmp_i = tmp_i->next;
		tmp_j = tmp_i->next;
	}
	res = mistakes / total_pairs;
	bench->disorder = res;
}

void	print_disorder(double dis)
{
	int		num;
	char	*tmp;
	size_t	i;

	num = dis * 100;
	dis = dis * 10000;
	tmp = ft_itoa((int)dis);
	i = ft_strlen(tmp);
	ft_dprintf(2, "%d.%c%c%%\n", num, tmp[i - 3], tmp[i - 2]);
	free(tmp);
}

void	algo_class(double dis)
{
	if (dis < 0.2)
		ft_dprintf(2, "O(n²)\n");
	else if (0.2 <= dis < 0.5)
		ft_dprintf(2, "O(n√n)\n");
	else if (dis >= 0.5)
		ft_dprintf(2, "O(n log n)\n");
}
