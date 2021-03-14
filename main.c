#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"


int main()
{
	va_list args;
	//printf("%10d", 10);
	//t_pars pars = ft_parsinit();

	char	*format = "%0*.*d\n";
	char	*printf_fmt = ft_strjoin("--printf ==>", format);
	char	*ft_printf_fmt = ft_strjoin("ftprintf ==>", format);

	printf("ft_printf return ==> %d\n", ft_printf(ft_printf_fmt, 4, -2, -12));
	printf("printf return ==> %d\n", printf(printf_fmt, 4, -2, -12));
	printf("ft_printf return ==> %d\n", ft_printf(ft_printf_fmt, 4, 2, -12));
	printf("printf return ==> %d\n", printf(printf_fmt, 4, 2, -12));
	va_end(args);
	return (0);
}
