/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaragay <swaragay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 08:05:24 by swaragay          #+#    #+#             */
/*   Updated: 2026/07/07 18:51:11 by swaragay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

int	which_conversion(const char *format, va_list args, int count)
{
	if (*format != '%')
	{
		if (*format == 'c')
			count = ft_char(va_arg(args, int));
		else if (*format == 's')
			count = ft_putstr(va_arg(args, const char *));
		else if (*format == 'p')
			count = ft_pointer(va_arg(args, void *), format);
		else if (*format == 'd' || *format == 'i')
			count = ft_num(va_arg(args, int));
		else if (*format == 'u')
			count = ft_unnum(va_arg(args, unsigned int));
		else if (*format == 'x' || *format == 'X')
			count = ft_puthex(va_arg(args, unsigned int), format);
	}
	else if (*format == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		tmp;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	tmp = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			tmp += which_conversion(format, args, count);
			if (tmp == -1)
				return (va_end(args), -1);
			count += tmp;
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	num;
// 	num = 0;
// 	num = ft_printf("%c\n", 'a');
// 	ft_printf("%d\n", 1+1);
// 	ft_printf("%p\n", &num);
// 	ft_printf("%x\n", 901297);
// 	ft_printf("%X\n", 901297);
// 	ft_printf("%i\n", 1+1);
// 	ft_printf("%u\n", 1+1);
// 	printf("%x\n", 901297);
// 	printf("%X\n", 901297);
// 	printf("%i\n", -1000);
// 	printf("%u\n", -1000);
// 	ft_printf(" %p \n", -1);
// 	ft_printf(" %p \n", 1);
// 	ft_printf(" %p \n", 15);
// 	ft_printf(" %p \n", 16);
// 	ft_printf(" %p \n", 17);
// 	ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
// 	ft_printf(" %p %p \n", INT_MIN, INT_MAX);
// 	ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
// 	ft_printf(" %p %p \n", 0, 0);
// 	char *a=NULL;
// 	printf("%s", a);
// printf("%u\n",4294967295);
// printf("%d\n",-2147483647);
// 	printf("%a",12345);
// write(1,'a',1);
//   }

// int	main(void)
// {
// 	printf("%d", printf(NULL));
// }

int	main(void)
{
	char			c;
	char			*s;
	void			*p;
	int				imax;
	int				imin;
	unsigned int	u;
	char			*null;
	int				ans;

	c = 'y';
	s = "cat is cute.";
	p = "hot dooog";
	imax = INT_MAX;
	imin = INT_MIN;
	u = -1;
	null = NULL;
	ans = 0;
	printf("\n### char & string ###\n");
	printf("=== %%c ===\n");
	printf("[original]\n");
	ans = printf("%c", c);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%c", c);
	printf("\n%d\n", ans);
	printf("=== %%s ===\n");
	printf("[original]\n");
	ans = printf("%s", s);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%s", s);
	printf("\n%d\n", ans);
	printf("=== %% ===\n");
	printf("[original]\n");
	ans = printf("%%%s%%", s);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%%%s%%", s);
	printf("\n%d\n", ans);
	printf("\n### Decimal ###\n");
	printf("=== %%d ===\n");
	printf("[original]\n");
	ans = printf("%d", imax);
	printf("\n%d\n", ans);
	ans = printf("%d", imin);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%d", imax);
	printf("\n%d\n", ans);
	ans = ft_printf("%d", imin);
	printf("\n%d\n", ans);
	printf("=== %%i ===\n");
	printf("[original]\n");
	ans = printf("%i", imax);
	printf("\n%d\n", ans);
	ans = printf("%i", imin);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%i", imax);
	printf("\n%d\n", ans);
	ans = ft_printf("%i", imin);
	printf("\n%d\n", ans);
	printf("=== %%u ===\n");
	printf("[original]\n");
	ans = printf("%u", imax);
	printf("\n%d\n", ans);
	ans = printf("%u", imin);
	printf("\n%d\n", ans);
	ans = printf("%u", u);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%u", imax);
	printf("\n%d\n", ans);
	ans = ft_printf("%u", imin);
	printf("\n%d\n", ans);
	ans = ft_printf("%u", u);
	printf("\n%d\n", ans);
	printf("\n### Hexadecimal ###\n");
	printf("=== %%x ===\n");
	printf("[original]\n");
	ans = printf("%x", imax);
	printf("\n%d\n", ans);
	ans = printf("%x", imin);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%x", imax);
	printf("\n%d\n", ans);
	ans = ft_printf("%x", imin);
	printf("\n%d\n", ans);
	printf("=== %%X ===\n");
	printf("[original]\n");
	ans = printf("%X", imax);
	printf("\n%d\n", ans);
	ans = printf("%x", imin);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%x", imax);
	printf("\n%d\n", ans);
	ans = ft_printf("%x", imin);
	printf("\n%d\n", ans);
	printf("=== %%p ===\n");
	printf("[original]\n");
	ans = printf("%p", p);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%p", p);
	printf("\n%d\n", ans);
	printf("\n### null ###\n");
	printf("=== (NULL) ===\n");
	printf("[original]\n");
	ans = printf("%s", null);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%s", null);
	printf("\n%d\n", ans);
	printf("=== (nil) ===\n");
	printf("[original]\n");
	ans = printf("%p", null);
	printf("\n%d\n", ans);
	printf("[ft]\n");
	ans = ft_printf("%p", null);
	printf("\n%d\n", ans);
	return (0);
}
