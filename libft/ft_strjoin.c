/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:46:14 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/09 17:22:04 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *stuck, char *buf)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!buf)
		return (ft_free(stuck));
	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(stuck) + ft_strlen(buf) + 1));
	if (!res)
		return (ft_free(stuck));
	while (stuck && stuck[i])
	{
		res[i] = stuck[i];
		++i;
	}
	while (buf[j])
	{
		res[i + j] = buf[j];
		++j;
	}
	res[i + j] = '\0';
	free(stuck);
	return (res);
}
