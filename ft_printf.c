/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:27:41 by ztouzri           #+#    #+#             */
/*   Updated: 2021/02/22 17:39:49 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int		ft_printf(const char *format, ...)
{
	va_list list;

	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_parser(&format[i + 1]);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (0);
}

t_pars	ft_parser(const char *format)
{
	int		i;
	t_pars	pars;

	pars = ft_parsinit();
	i = 0;
	while (format[i])
	{
		if (ft_isin("cspdiuxX%", format[i]))
			pars.convert = format[i];
		else if (ft_isin("0123456789-.*", format[i]))
		{
			ft_flag(format[i], pars);
		}
	}
}

void	ft_flag(const char *format, t_pars pars)
{
	int		i;
	char	*width;

	i = 0;
	if (format[i] == '-')
		pars.minus = 1;
	else if (format[0] == '0')
	{
		pars.zero = 1;
		i++;
	}
	if (ft_isdigit(format[i]))
	{
		while (ft_isdigit(format[i + j]))
			j++;
		width = ft_substr(format[i], 0, j);
		pars.width = ft_atoi(width);
		i += j;
	}
}

t_pars	ft_parsinit(void)
{
	t_pars pars;

	pars.converter = 0;
	pars.zero = 0;
	pars.minus = 0;
	pars.precision = 0;
	pars.width = 0;
	return (pars);
}
