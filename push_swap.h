/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:27:40 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/21 19:09:38 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_dprintf/ft_dprintf.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_bench
{
	double			disorder;
	int				strategy;
	int				total_ops;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_bench;

typedef struct s_config
{
	int				strategy_mode;
	int				bench_flag;
	t_bench			bench;
}					t_config;

typedef struct s_num
{
	int				value;
	int				index;
	int				min_index;
	struct s_num	*next;
	struct s_num	*prev;
}					t_num;

/*parse*/
int					main(int argc, char **argv);
void				init_program(t_config *config, t_bench *bench);
int					run_parse(int argc, char **argv, t_config *config,
						t_num **stack_a);
int					run_algo(t_num **stack_a, t_num **stack_b, t_config *config,
						t_bench *bench);
int					ft_parse(int argc, char **argv, t_config *config,
						t_num **stack_a);
int					save_option(char *arg, t_config *config);
int					process_numeric_argument(char *arg_str, t_num **stack_a);
char				**split_and_free(char *arg_str);
long				ft_atol(const char *nptr);
int					is_valid_num_str(char *str);
t_num				*ft_mk_newlst(long nb);
int					is_duplicate(t_num *stack, int value);
void				add_node_back(t_num **stack, t_num *new_node);
void				free_stack(t_num **stack);
int					free_twostacks(t_num **stack_a, t_num **stack_b,
						int status);
int					free_split(char **split, int status);

/*algorithm*/
void				adaptive(t_num **stack_a, t_num **stack_b, t_bench *bench);
void				complex(t_num **stack_a, t_num **stack_b, t_bench *bench);
int					count_bitsize(int num);
void				medium(t_num **stack_a, t_num **stack_b, t_bench *bench);
int					compute_chunksize(t_num *stack_a);
void				move_b(t_num **stack_a, t_num **stack_b, t_bench *bench);
void				simple(t_num **stack_a, t_num **stack_b, t_bench *bench);
void				put_index(t_num **stack_a);
void				move_top(t_num **stack_a, t_num *min, t_bench *bench);

/*bench*/
void				compute_disorder(t_num *stack_a, t_bench *bench);
void				print_disorder(double dis);
void				algo_class(double dis);
void				print_bench(t_bench *bench);

/*command*/
void				lst_swaptop(t_num **stack_a);
void				lst_movefirst(t_num **stack_a, t_num **stack_b);
void				lst_pushup(t_num **stack_a);
void				lst_pushdown(t_num **stack_a);
void				pa(t_num **stack_a, t_num **stack_b, t_bench *bench);
void				pb(t_num **stack_a, t_num **stack_b, t_bench *bench);
void				ra(t_num **stack_a, t_bench *bench);
void				rb(t_num **stack_b, t_bench *bench);
void				rr(t_num **stack_a, t_num **stack_b, t_bench *bench);
void				rra(t_num **stack_a, t_bench *bench);
void				rrb(t_num **stack_b, t_bench *bench);
void				rrr(t_num **stack_a, t_num **stack_b, t_bench *bench);
void				sa(t_num **stack_a, t_bench *bench);
void				sb(t_num **stack_b, t_bench *bench);
void				ss(t_num **stack_a, t_num **stack_b, t_bench *bench);

/*libft*/
char				*ft_free(char *s);
int					ft_isdigit(int c);
t_num				*ft_lstlast(t_num *stack_a);
int					ft_lstsize(t_num *stack_a);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_bzero(void *s, size_t n);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);

/*min_index*/
void				coordinate_compression(t_num *stack_a);

#endif
