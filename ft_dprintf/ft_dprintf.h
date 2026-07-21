/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:21:04 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/21 17:02:21 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/**printf**/
int		ft_char(int fd, int c);
int		ft_putstr(int fd, const char *s);
int		ft_pointer(int fd, void *p, const char *format);
int		ft_num(int fd, int num);
int		ft_unnum(int fd, unsigned int num);
int		ft_puthex(int fd, unsigned long num, const char *format);
int		which_conversion(int fd, const char *format, va_list args, int count);
int		ft_dprintf(int fd, const char *format, ...);

size_t	ft_intlen(long n);
char	*ft_putnbr(long n, char *dest, long len);
char	*ft_itoa(int n);
int		res_disorder(double dis);

#endif
