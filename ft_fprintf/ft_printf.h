#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// # include <limits.h>
// # include <stdint.h>
// # include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/**printf**/
int	ft_char(int c);
int	ft_putstr(const char *s);
int	ft_pointer(void *p, const char *format);
int	ft_num(int num);
int	ft_unnum(unsigned int num);
int	ft_puthex(unsigned long num, const char *format);
int	which_conversion(const char *format, va_list args, int count);
int	ft_printf(const char *format, ...);

size_t	ft_intlen(long n);
char	*ft_putnbr(long n, char *dest, long len);
char	*ft_itoa(int n);
int	res_disorder(double dis);
size_t	ft_strlen(const char *s);

#endif
