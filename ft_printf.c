/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:54:56 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/04 15:43:53 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		res;
	int		i;
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
			i++;
			if (ft_parser(&format[i], &pars, args) == -1)
				return (-1);
			i += ft_parser(&format[i], &pars, args);
		}
		else
			res += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (res);
}
