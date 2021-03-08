#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"


int main()
{
	va_list args;
	//printf("%10d", 10);
	//t_pars pars = ft_parsinit();

	char *format = "%4d\n";
	char *printf_fmt = ft_strjoin("--printf ==>", format);
	char *ft_printf_fmt = ft_strjoin("ftprintf ==>", format);
	int	d = INT_MIN;
	//int width = 0;
	//int precision = 0;
	printf("ft_printf return ==> %d\n", ft_printf(ft_printf_fmt, d));
	printf("printf return ==> %d\n", printf(printf_fmt, d));
	//ft_printf(format, width, precision, "fweoifjwiewfwe");
	//printf(format, width, precision, "fweoifjwiewfwe");
	/*printf("pars->width == %d\n", pars.width);
	printf("pars->precision == %d\n", pars.precision);
	printf("pars->convert == %c\n", pars.convert);*/
	va_end(args);
	return (0);
}
