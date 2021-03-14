/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:25:21 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/14 18:25:21 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pars	ft_parsinit(void)
{
	t_pars pars;

	pars.zero = 0;
	pars.minus = 0;
	pars.width = 0;
	pars.neg = 0;
	pars.null = 0;
	pars.precision = 0;
	pars.precision_on = 0;
	pars.convert = 0;
	pars.str = 0;
	return (pars);
}

int		ft_zerominus_pars(const char *format, t_pars *pars)
{
	int	i;
	int	zero;

	zero = 1;
	i = 0;
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
		{
			pars->minus = 1;
			zero = 0;
		}
		if (format[i] == '0')
			pars->zero = 1;
		i++;
	}
	if (!zero)
		pars->zero = 0;
	return (i);
}

int		ft_precision_pars(const char *format, t_pars *pars, va_list args)
{
	int	i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		pars->precision_on = 1;
		if (format[i] == '*')
		{
			pars->precision = va_arg(args, int);
			if (pars->precision < 0)
				pars->precision_on = 0;
			i++;
		}
		else if (ft_isdigit(format[i]))
			i += ft_digitconvert(&format[i], pars, 0);
	}
	return (i);
}

int		ft_widthprecision_pars(const char *format, t_pars *pars, va_list args)
{
	int		i;

	i = 0;
	if (format[i] == '*')
	{
		pars->width = va_arg(args, int);
		if (pars->width < 0)
		{
			pars->width *= -1;
			pars->minus = 1;
		}
		i++;
		i += ft_precision_pars(&format[i], pars, args);
	}
	else if (ft_isdigit(format[i]))
	{
		i += ft_digitconvert(&format[i], pars, 1);
		i += ft_precision_pars(&format[i], pars, args);
	}
	else
		i += ft_precision_pars(&format[i], pars, args);
	return (i);
}

int		ft_parser(const char *format, t_pars *pars, va_list args)
{
	int	i;

	*pars = ft_parsinit();
	i = 1;
	i += ft_zerominus_pars(&format[i], pars);
	i += ft_widthprecision_pars(&format[i], pars, args);
	if (ft_isin("cspdiuxX%", format[i]) != -1)
	{
		pars->convert = format[i];
		return (i);
	}
	return (-1);
}
