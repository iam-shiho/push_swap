/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttatsuno <ttatsuno@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 09:42:56 by ttatsuno          #+#    #+#             */
/*   Updated: 2026/07/21 16:50:51 by ttatsuno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	run_algo(t_num **stack_a, t_num **stack_b, t_config *config, t_bench *bench)
{
	ft_bzero(bench, sizeof(t_bench));
	if (config -> strategy_mode == 1)
		simple(stack_a, stack_b, bench);
	else if (config -> strategy_mode == 2)
		medium(stack_a, stack_b, bench);
	else if (config -> strategy_mode == 3)
		complex(stack_a, stack_b, bench);
	else if (config -> strategy_mode == 0)
		adaptive(stack_a, stack_b, bench);
	return (0);
}

int	run_parse(int argc, char **argv, t_config *config, t_num **stack_a)
{
	if (ft_parse (argc, argv, config, stack_a) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

void	init_program(t_config *config, t_bench *bench)
{
	ft_bzero(config, sizeof(t_config));
	ft_bzero(bench, sizeof(t_bench));
	config->strategy_mode = -1;
}

int	main(int argc, char **argv)
{
	t_config	config;
	t_bench		bench;
	t_num		*stack_a;
	t_num		*stack_b;
	int			ret;

	stack_a = NULL;
	stack_b = NULL;
	init_program(&config, &bench);
	if (argc < 2)
		return (0);
	ret = run_parse (argc, argv, &config, &stack_a);
	if (ret == 1)
		return (free_twostacks(&stack_a, &stack_b, 1));
	if (stack_a == NULL)
		return (0);
	compute_disorder(stack_a, &bench);
	coordinate_compression(stack_a);
	run_algo(&stack_a, &stack_b, &config, &bench);
	if (config.bench_flag == 1)
		print_bench (&bench);
	return (free_twostacks(&stack_a, &stack_b, 0));
}
