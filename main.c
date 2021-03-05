#include <stdio.h>
#include "ft_printf.h"


int main()
{
	va_list args;
	//printf("%10d", 10);
	//t_pars pars = ft_parsinit();

	char *format = "%*.*s\n";
	int width = -100;
	int precision = 10;
	ft_printf(format, width, precision, "salut c'est zak");
	printf(format, width, precision, "salut c'est zak");
	/*printf("pars->width == %d\n", pars.width);
	printf("pars->precision == %d\n", pars.precision);
	printf("pars->convert == %c\n", pars.convert);*/
	va_end(args);
	return (0);
}
