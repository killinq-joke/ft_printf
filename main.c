#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"


int main()
{
	va_list args;
	//printf("%10d", 10);
	//t_pars pars = ft_parsinit();

	char	*format = "%-c\n";
	char	*printf_fmt = ft_strjoin("--printf ==>", format);
	char	*ft_printf_fmt = ft_strjoin("ftprintf ==>", format);

	printf("ft_printf return ==> %d\n", ft_printf(ft_printf_fmt, '\t'));
	printf("printf return ==> %d\n", printf(printf_fmt, '\t'));
	printf("ft_printf return ==> %d\n", ft_printf(ft_printf_fmt, 0));
	printf("printf return ==> %d\n", printf(printf_fmt, 0));
	va_end(args);
	return (0);
}
