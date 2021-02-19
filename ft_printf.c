/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:27:41 by ztouzri           #+#    #+#             */
/*   Updated: 2021/02/19 13:57:34 by ztouzri          ###   ########.fr       */
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

void	*ft_parser(const char *format)
{
	int i;
	t_pars pars;

	i = 0;
	if (format[0] == '0')
	{
		pars.zero = 1;
		i++;
	}
	while (format[i])
	{
		
		i++;
	}
}
