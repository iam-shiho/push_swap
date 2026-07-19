/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:10:24 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 22:00:12 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_num_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] == '\0')
			return (-1);
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	process_numeric_argument(char *arg_str, t_num **stack_a)
{
	char		**split_arr;
	int			str_i;
	long long	num;
	t_num		*new_node;

	split_arr = ft_split(arg_str, ' ');
	if (!split_arr)
		return (-1);
	if (!split_arr[0])
		return (free_split(split_arr), -1);
	str_i = 0;
	while (split_arr[str_i])
	{
		if (!is_valid_num_str(split_arr[str_i]))
			return (-1);
		num = ft_atol(split_arr[str_i]);
		if (num > INT_MAX || num < INT_MIN)
			return (free_split(split_arr), -1);
		if (is_duplicate(*stack_a, num))
			return (-1);
		new_node = ft_mk_newlst(num);
		if (!new_node)
			return (free_split(split_arr), -1);
		add_node_back(stack_a, new_node);
		str_i++;
	}
	return (free_split(split_arr), 0);
}

int	save_option(char *arg, t_config *config)
{
	if (ft_strncmp(arg, "--bench", 7) != 0 && config->strategy_mode != -1)
		return (-1);
	if (ft_strncmp(arg, "--simple", 8) == 0)
		config->strategy_mode = 1;
	else if (ft_strncmp(arg, "--medium", 8) == 0)
		config->strategy_mode = 2;
	else if (ft_strncmp(arg, "--complex", 8) == 0)
		config->strategy_mode = 3;
	else if (ft_strncmp(arg, "--adaptive", 10) == 0)
		config->strategy_mode = 0;
	else if (ft_strncmp(arg, "--bench", 7) == 0)
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

int	main(int argc, char **argv)
{
	t_config	config;
	t_num		*stack_a;
	t_num		*stack_b;
	t_bench *bench;

	stack_a = NULL;
	stack_b = NULL;
	ft_bzero(&config, sizeof(t_config));
	config.strategy_mode = -1;
	if (argc < 2)
		return (0);
	if (ft_parse(argc, argv, &config, &stack_a) == -1)
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		return (1);
	}
	if (stack_a == NULL)
		return (0);
	coordinate_compression(stack_a);
	return (0);
}
