/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:24:15 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/14 19:07:44 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_block(t_pars *pars)
{
	int i;

	i = 0;
	if (pars->neg == 1)
		i += ft_putchar('-');
	if (pars->convert == 'p')
		i += ft_putstr("0x");
	while (pars->precision-- > (int)ft_strlen(pars->str))
		i += ft_putchar('0');
	i += ft_putstr(pars->str);
	if (pars->convert == 'c' && pars->str[0] == 0)
		i += ft_putchar(0);
	if (pars->width > pars->precision +
	(pars->convert == 'c' && pars->str[0] == 0))
		while (pars->width - i > 0)
			i += ft_putchar(' ');
	return (i);
}

int		ft_minus_handler(t_pars *pars)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (pars->null && pars->precision == 0 && pars->precision_on)
	{
		if (pars->width > pars->precision)
			while (pars->width - i > 0)
				i += ft_putchar(' ');
		return (i);
	}
	if (pars->convert == 's')
	{
		while (pars->str[j] && (pars->precision-- != 0 || !pars->precision_on))
			j += ft_putchar(pars->str[j]);
		i += j;
		while (pars->width - i > 0)
			i += ft_putchar(' ');
	}
	else
		i += ft_block(pars);
	return (i);
}

int		ft_block1(t_pars *pars)
{
	int i;
	int j;
	int charnb;

	i = 0;
	j = 0;
	if (pars->precision_on)
	{
		if (pars->precision > (int)ft_strlen(pars->str))
			charnb = ft_strlen(pars->str);
		else
			charnb = pars->precision;
	}
	else
		charnb = (int)ft_strlen(pars->str);
	while (pars->width-- > charnb)
		i += ft_putchar(pars->zero ? '0' : ' ');
	while (pars->str[j] && (pars->precision-- != 0 || !pars->precision_on))
		j += ft_putchar(pars->str[j]);
	i += j;
	return (i);
}

int		ft_block2(t_pars *pars)
{
	int i;

	i = 0;
	if (pars->neg == 1 && pars->zero && !pars->precision_on)
		i += ft_putchar('-');
	while (pars->width - ((pars->convert == 'p') ? 2 : 0) - pars->neg >
	(int)ft_strlen(pars->str) + (pars->convert == 'c' && pars->str[0] == 0)
			&& pars->width-- - ((pars->convert == 'p') ? 2 : 0)
			- pars->neg > pars->precision)
		i += ft_putchar((pars->zero && !pars->precision_on) ? '0' : ' ');
	if (pars->convert == 'p')
		i += ft_putstr("0x");
	if (pars->neg == 1 && (!pars->zero || pars->precision_on))
		i += ft_putchar('-');
	while (pars->precision-- > (int)ft_strlen(pars->str))
		i += ft_putchar('0');
	i += ft_putstr(pars->str);
	if (pars->convert == 'c' && pars->str[0] == 0)
		i += ft_putchar(0);
	return (i);
}

int		ft_nominus_handler(t_pars *pars)
{
	int i;

	i = 0;
	if (pars->null && pars->precision == 0 && pars->precision_on)
	{
		if (pars->width > pars->precision)
			while (pars->width - i > 0)
				i += ft_putchar(' ');
		return (i);
	}
	if (pars->convert == 's')
		i += ft_block1(pars);
	else
		i += ft_block2(pars);
	return (i);
}
