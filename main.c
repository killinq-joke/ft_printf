#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"


int main()
{
	va_list args;
	//printf("%10d", 10);
	//t_pars pars = ft_parsinit();

	char	*format = "%x\n";
	char	*printf_fmt = ft_strjoin("--printf ==>", format);
	char	*ft_printf_fmt = ft_strjoin("ftprintf ==>", format);
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf("ft_printf return ==> %d\n", ft_printf(ft_printf_fmt, 0));
	printf("printf return ==> %d\n", printf(printf_fmt, 0));
	va_end(args);
	return (0);
}
