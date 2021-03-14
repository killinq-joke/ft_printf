/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:54:56 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/14 09:09:03 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_inttostr(t_pars *pars, va_list args)
{
	long nb;

	nb = 0;
	if (ft_isin("di", pars->convert) != -1)
	{
		nb = va_arg(args, int);
		if (nb < 0)
			pars->neg = 1;
		if (nb == 0)
			pars->null = 1;
		pars->str = ft_itoa(nb);
	}
	else if (pars->convert == 'x')
	{
		nb = va_arg(args, unsigned int);
		if (nb == 0)
			pars->null = 1;
		pars->str = ft_itoa_base(nb, "0123456789abcdef");
	}
	else if (pars->convert == 'X')
	{
		nb = va_arg(args, unsigned int);
		if (nb == 0)
			pars->null = 1;
		pars->str = ft_itoa_base(nb, "0123456789ABCDEF");
	}
	else if (pars->convert == 'u')
	{
		nb = va_arg(args, unsigned int);
		if (nb == 0)
			pars->null = 1;
		pars->str = ft_utoa(nb);
	}
}

void	ft_converttostr(t_pars *pars, va_list args)
{
	char	*str;
	if (pars->convert == 'c')
	{
		pars->str = malloc(2);
		pars->str[0] = va_arg(args, int);
		pars->str[1] = '\0';
	}
	else if (pars->convert == 's')
	{
		str = va_arg(args, char *);
		if (str == 0)
			pars->str = ft_strdup("(null)");
		else
			pars->str = ft_strdup(str);
	}
	else if (ft_isin("diuxX", pars->convert) != -1)
		ft_inttostr(pars, args);
	else if (pars->convert == 'p')
		pars->str = ft_ztoa_base(va_arg(args, long long), "0123456789abcdef");
	else if (pars->convert == '%')
		pars->str = ft_strdup("%");
}

int		ft_printf(const char *format, ...)
{
	int		res;
	int		i;
	int		pars_ret;
	va_list	args;
	t_pars	pars;

	va_start(args, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((pars_ret = ft_parser(&format[i], &pars, args)) == -1)
				return (-1);
			i += pars_ret;
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
