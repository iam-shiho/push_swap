/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttatsuno <ttatsuno@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 09:46:01 by ttatsuno          #+#    #+#             */
/*   Updated: 2026/07/21 16:38:34 by ttatsuno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substring;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
	{
		return (NULL);
	}
	i = (size_t)start;
	j = 0;
	while (j < len && s[i])
	{
		substring[j] = s[i];
		i++;
		j++;
	}
	substring[j] = '\0';
	return (substring);
}

// int	main (void)
// {
// 	char	*str;
// 	char	*new;
//
// 	str = "1940013Machida-city";
// 	new = ft_substr(str, 7, 10);
// 	printf ("%s\n", new);
// 	return (0);
// }
