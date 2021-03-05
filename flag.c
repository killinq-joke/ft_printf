/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:54:46 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/05 14:30:44 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		strprecision_handler(char *str, int precision)
{
	int	res;

	res = 0;
	while (str[res] && res < precision)
		res += ft_putchar(str[res]);
	return (res);
}

int		precision_handler(char *str, int precision)
{
	int		res;

	res = 0;
	while (res + (int)ft_strlen(str) < precision)
		res += ft_putchar('0');
	res += ft_putstr(str);
	return (res);
}

int		width_handler(char *str, int width, int minus, int zero)
{
	int	res;

	res = 0;
	if (minus)
	{
		res += ft_putstr(str);
		while (res < width)
			res += ft_putchar(' ');
	}
	else
	{
		while (res + (int)ft_strlen(str) < width)
			res += ft_putchar(zero ? '0' : ' ');
		res += ft_putstr(str);
	}
	return (res);
}

int		ft_minus_handler(t_pars *pars)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (pars->convert == 's')
	{
		while (pars->str[j] && pars->precision-- != 0)
			j += ft_putchar(pars->str[j]);
		i += j;
		if (pars->width > pars->precision)
			while (pars->width - i > 0)
				i += ft_putchar(' ');
	}
	else
	{
		if (pars->convert == 'p')
			i += ft_putstr("0x");
		while (pars->precision-- > (int)ft_strlen(pars->str))
			i += ft_putchar('0');
		i += ft_putstr(pars->str);
		if (pars->width > pars->precision)
			while (pars->width - i > 0)
				i += ft_putchar(' ');
	}
	return (i);
}

int		ft_nominus_handler(t_pars *pars)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (pars->convert == 's')
	{
		while (pars->width > pars->precision
				&& pars->width-- > pars->precision)
			i += ft_putchar(pars->zero ? '0' : ' ');
		while (pars->str[j] && pars->precision-- != 0)
			j += ft_putchar(pars->str[j]);
		i += j;
	}
	else
	{
		while (pars->width - ((pars->convert == 'p') ? 2 : 0) > (int)ft_strlen(pars->str)
				&& pars->width-- - ((pars->convert == 'p') ? 2 : 0) > pars->precision)
			i += ft_putchar((pars->zero && pars->precision_on) ? '0' : ' ');
		if (pars->convert == 'p')
			i += ft_putstr("0x");
		while (pars->precision-- > (int)ft_strlen(pars->str))
			i += ft_putchar('0');
		i += ft_putstr(pars->str);
	}
	return (i);
}

int		ft_translate(t_pars *pars)
{
	int	i;

	i = 0;
	if (pars->convert == 'c')
		pars->precision = 0;
	if (pars->minus)
		i += ft_minus_handler(pars);
	else
		i += ft_nominus_handler(pars);
	return (i);
}