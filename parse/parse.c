/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 19:37:11 by ttatsuno          #+#    #+#             */
/*   Updated: 2026/07/21 16:12:11 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**split_and_free(char *arg_str)
{
	char		**split_arr;

	split_arr = ft_split(arg_str, ' ');
	if (!split_arr)
		return (NULL);
	if (!split_arr[0])
	{
		free_split(split_arr, 0);
		return (NULL);
	}
	return (split_arr);
}

int	process_numeric_argument(char *arg_str, t_num **stack_a)
{
	char		**split_arr;
	int			str_i;
	long		num;
	t_num		*new_node;

	split_arr = split_and_free(arg_str);
	if (!split_arr)
		return (-1);
	str_i = 0;
	while (split_arr[str_i])
	{
		if (!is_valid_num_str(split_arr[str_i]))
			return (free_split(split_arr, -1));
		num = ft_atol(split_arr[str_i]);
		if (num > INT_MAX || num < INT_MIN)
			return (free_split(split_arr, -1));
		if (is_duplicate(*stack_a, (int)num))
			return (free_split(split_arr, -1));
		new_node = ft_mk_newlst(num);
		if (!new_node)
			return (free_split(split_arr, -1));
		add_node_back(stack_a, new_node);
		str_i++;
	}
	return (free_split(split_arr, 0));
}

int	save_option(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--bench", 8) != 0 && config->strategy_mode != -1)
		return (-1);
	if (ft_strncmp(arg, "--simple", 9) == 0)
		config->strategy_mode = 1;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		config->strategy_mode = 2;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		config->strategy_mode = 3;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		config->strategy_mode = 0;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		config->bench_flag = 1;
	else
		return (-1);
	return (0);
}

int	ft_parse(int argc, char **argv, t_config *config, t_num **stack_a)
{
	int	ap;

	ap = 1;
	while (ap < argc)
	{
		if (ft_strncmp(argv[ap], "--", 2) == 0)
		{
			if (save_option(argv[ap], config) == -1)
				return (-1);
		}
		else
		{
			if (process_numeric_argument(argv[ap], stack_a) == -1)
				return (-1);
		}
		ap++;
	}
	if (config->strategy_mode == -1)
		config->strategy_mode = 0;
	return (0);
}
