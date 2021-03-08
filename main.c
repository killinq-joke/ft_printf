#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"


int main()
{
	va_list args;
	//printf("%10d", 10);
	//t_pars pars = ft_parsinit();

	char	*format = "%0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d\n";
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
	printf("ft_printf return ==> %d\n", ft_printf(ft_printf_fmt, i, 3, -2, j, 3, -2, k, 3, -2, l, 3, -2, m, 3, -2, c, 3, -2, e, 3, -2, d,   3, -2);
	printf("printf return ==> %d\n", printf(printf_fmt, i, 3, -2, j, 3, -2, k, 3, -2, l, 3, -2, m, 3, -2, c, 3, -2, e, 3, -2, d, 3, -2));
	//ft_printf(format, width, precision, "fweoifjwiewfwe");
	//printf(format, width, precision, "fweoifjwiewfwe");
	/*printf("pars->width == %d\n", pars.width);
	printf("pars->precision == %d\n", pars.precision);
	printf("pars->convert == %c\n", pars.convert);*/
	printf("salut %3d", -12);
	va_end(args);
	return (0);
}
