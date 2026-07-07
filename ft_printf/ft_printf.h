/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:43:39 by swaragay          #+#    #+#             */
/*   Updated: 2026/06/22 14:20:46 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>

/**printf**/
int	ft_char(int c);
int	ft_putstr(const char *s);
int	ft_pointer(void *p, const char *format);
int	ft_num(int num);
int	ft_unnum(unsigned int num);
int	ft_puthex(unsigned long num, const char *format);
int	which_conversion(const char *format, va_list args, int count);
int	ft_printf(const char *format, ...);

#endif
