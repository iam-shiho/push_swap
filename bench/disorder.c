/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 17:32:25 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 17:22:30 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// disoderを計算して0.00~1までの数字を出力 + 構造体に書き込む
double	compute_disorder(t_num **stack_a, t_bench *bench)
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
	bench->res_dis = res_disorder(res);
	return (res);
}

//キモいけど文字列を作成する関数
char	res_disorder(double dis)
{
	char	*res;
	char	*tmp;
	size_t	i;

	res = (char *)malloc(sizeof(char) * 7);
	if (!res)
		return (NULL);
	//整数部分を入れる
	dis = dis * 100;
	res = ft_strcpy(res, ft_itoa((int)dis));
	//小数点を入れる
	res[3] = '.';
	res[4] = '\0';
	//小数点以下を入れる
	dis = dis * 100;
	tmp = ft_itoa((int)dis);
	i = ft_strlen(tmp);
	res = ft_strcpy(&res[4], &tmp[i - 3]);
	res[6] = '%';
	res[7] = '\0';
	return (res);
}
