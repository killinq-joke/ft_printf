/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:54:56 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/05 15:00:14 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_converttostr(t_pars *pars, va_list args)
{
	if (pars->convert == 'c')
	{
		pars->str = malloc(2);
		pars->str[0] = va_arg(args, int);
		pars->str[1] = '\0';
	}
	else if (pars->convert == 's')
		pars->str = va_arg(args, char *);
	else if (ft_isin("di", pars->convert) != -1)
		pars->str = ft_itoa(va_arg(args, int));
	else if (pars->convert == 'x')
		pars->str = ft_itoa_base(va_arg(args, int), "0123456789abcdef");
	else if (pars->convert == 'X')
		pars->str = ft_itoa_base(va_arg(args, int), "0123456789ABCDEF");
	else if (pars->convert == 'u')
		pars->str = ft_itoa(va_arg(args, unsigned int));
	else if (pars->convert == 'p')
		pars->str = ft_ztoa_base(va_arg(args, size_t), "0123456789abcdef");
	else if (pars->convert == '%')
		pars->str = "%";
}

int		ft_printf(const char *format, ...)
{
	int		res;
	int		i;
	int		pars_ret;
	va_list	args;
	t_pars	pars;

	va_start(args, format);
	pars = ft_parsinit();
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((pars_ret = ft_parser(&format[i], &pars, args)) == -1)
				return (-1);
			i += pars_ret;
			/*printf("pars.zero == %d\n", pars.zero);
			printf("pars.width == %d\n", pars.width);
			printf("pars.precision == %d\n", pars.precision);
			printf("pars.minus == %d\n", pars.minus);
			printf("pars.convert == %c\n", pars.convert);*/
			ft_converttostr(&pars, args);
			res += ft_translate(&pars);
		}
		else
			res += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (res);
}
