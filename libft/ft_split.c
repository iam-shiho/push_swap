/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:34:53 by ttatsuno          #+#    #+#             */
/*   Updated: 2026/07/21 16:30:36 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	**free_all(char **array, size_t i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				++s;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t		ct_words;
	size_t		i;
	char		**array;
	char		*str;
	char const	*start;

	ct_words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (ct_words + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < ct_words)
	{
		while (*s && *s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		str = ft_substr(start, 0, (s - start));
		if (!str)
			return (free_all(array, i));
		array[i++] = str;
	}
	array[i] = NULL;
	return (array);
}

// #include <stdio.h>
//
// int	main(void)
// {
// 	char	*string;
// 	char	deli;
// 	char	**array_p;
// 	int		i;
//
// 	string = "AAAAA.....BBBBB...cccc";
// 	deli = '.';
// 	array_p = ft_split(string, deli);
// 	i = 0;
// 	while (*array_p[i] != '\0')
// 	{
// 		printf("i：%s\n", array_p[i]);
// 		i++;
// 	}
// 	return (0);
// }
