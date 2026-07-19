/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:27:40 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/19 19:45:28 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_dprintf/ft_dprintf.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

//数字をまとめる構造体
typedef struct s_config
{
	int		strategy_mode; // 0: adaptive, 1: simple, 2: medium, 3: complex
	int		bench_flag;// 0: オフ, 1: オン (--bench用)
	t_bench	bench;// ベンチマーク計測用データ
}		t_config;

//各数字に意味づけをする構造体　ソートするやつ　
typedef struct s_num
{
	int value;            // 記入されたの数値
	int index;            // 各アルゴリズムで使用する前からのインデックス
	int min_index; //座標圧縮
	struct s_stack *next; // 次の要素へのポインター
	struct s_stack *prev; // 前の要素のポインター
}						t_num;

// benchの中身を保存する構造体
typedef struct s_bench
{
	double				disorder;
	// 混沌度（0.00〜1.00なので、floatかdoubleをしようする）（intだと小数点以下が表せない）%はft_printfで出力するのかな？？
	int strategy; // 使用したアルゴリズム 1:simple 2:medium 3:complex 4:adaptive
	int total_ops;  // 総操作回数

	// 各コマンドのカウンター
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_bench;

/*parse*/
int		ft_parse(int argc, char **argv, t_config *config, t_num **stack_a);
int		save_option(char *arg, t_config *config);
int		process_numeric_argument(char *arg_str, t_num **stack_a);
int		is_valid_num_str(char *str);
void	free_stack(t_num **stack);
void	free_split(char **split);
t_num	*ft_mk_newlst(long nb);
int		is_duplicate(t_num *stack, int value);
void	add_node_back(t_num **stack, t_num *new_node);
int		ft_isdigit(int c);
long	ft_atol(const char *nptr);
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);

/*algorithm*/
void	complex(t_num **stack_a, t_num **stack_b, t_num **bench);
int	count_bitsize(int num);
void	medium(t_num **stack_a, t_num **stack_b, t_num **bench);
int	compute_chunksize(t_num **stack_a);
void	move_b(t_num **stack_a, t_num **stack_b, t_num **bench);
void	simple(t_num **stack_a, t_num **stack_b, t_num **bench);
int	put_index(t_num **stack_a);
void	move_top(t_num **stack_a, t_num *min, t_num **bench);

/*bench*/
void	compute_disorder(t_num **stack_a, t_bench **bench);
void	print_disorder(double dis);
void	algo_class(double dis);
void	print_bench(t_bench *bench);

/*command*/
void	lst_swaptop(t_num **stack_a);
void	lst_movefirst(t_num **stack_a, t_num **stack_b);
void	lst_pushup(t_num **stack_a);
void	lst_pushdown(t_num **stack_a);
void	pa(t_num **stack_a, t_num **stack_b, t_bench **bench);
void	pb(t_num **stack_a, t_num **stack_b, t_bench **bench);
void	ra(t_num **stack_a, t_bench **bench);
void	rb(t_num **stack_b, t_bench **bench);
void	rr(t_num **stack_a, t_num **stack_b, t_bench **bench);
void	rra(t_num **stack_a, t_bench **bench);
void	rrb(t_num **stack_b, t_bench **bench);
void	rrr(t_num **stack_a, t_num **stack_b, t_bench **bench);
void	sa(t_num **stack_a, t_bench **bench);
void	sb(t_num **stack_b, t_bench **bench);
void	ss(t_num **stack_a, t_num **stack_b, t_bench **bench);

/*libft*/
char	*ft_free(char *s);
int	ft_isdigit(int c);
t_num	*ft_lstlast(t_num **stack_a);
int	ft_lstsize(t_num *stack_a);
char	ft_strlcpy(char *dst, char *src);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *stuck, char *buf);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

/*min_index*/
void	coordinate_compression(t_num *stack_a);



#endif

/*
データを順番に並べたデータ構造を"連結リスト"
リストを構成する一つ一つの要素を"ノード" (データだけでなく、ノード間を連結（リンク）するための情報を含む)

構造体は型の名前
*/

/*
ライブコーディング
benchの構造体の中にint print みたいな変数をつくる
必要なら一　いらないなら０かなにもいれない？ようにして
あとは各こまんどのft_printfを条件分岐する
if (bench->print==1)
	ft_printf("pa\n");
*/
