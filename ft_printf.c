/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:41 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/14 18:24:44 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_digitconvert(const char *format, t_pars *pars, int is_width)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	tmp = ft_substr(format, 0, i);
	if (is_width)
		pars->width = ft_atoi(tmp);
	else
		pars->precision = ft_atoi(tmp);
	free(tmp);
	return (i);
}

long	ft_di(t_pars *pars, va_list args)
{
	long nb;

	if (ft_isin("di", pars->convert) != -1)
	{
		nb = va_arg(args, int);
		if (nb < 0)
			pars->neg = 1;
		if (nb == 0)
			pars->null = 1;
		pars->str = ft_itoa(nb);
		return (nb);
	}
	return (0);
}

void	ft_inttostr(t_pars *pars, va_list args)
{
	long nb;

	nb = ft_di(pars, args);
	if (pars->convert == 'x')
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
