/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:54:46 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/04 11:19:38 by ztouzri          ###   ########.fr       */
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
