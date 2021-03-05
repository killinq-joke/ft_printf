#include <stdio.h>
#include "ft_printf.h"


int main()
{
	va_list args;
	//printf("%10d", 10);
	//t_pars pars = ft_parsinit();

	char *format = "%.20x\n";
	//int width = 0;
	//int precision = 0;
	ft_printf(format, -32);
	printf(format, -32);
	//ft_printf(format, width, precision, "fweoifjwiewfwe");
	//printf(format, width, precision, "fweoifjwiewfwe");
	/*printf("pars->width == %d\n", pars.width);
	printf("pars->precision == %d\n", pars.precision);
	printf("pars->convert == %c\n", pars.convert);*/
	va_end(args);
	return (0);
}
