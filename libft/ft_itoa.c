/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:46:39 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/08 10:10:05 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*res;
	size_t	i;
	int		sign;
	long	ntmp;

	ntmp = n;
	if (!(res = malloc(13)))
		return (NULL);
	if ((sign = 1) && ntmp < 0)
	{
		ntmp *= -1;
		sign = -1;
	}
	i = 0;
	if (ntmp == 0)
		res[i++] = 0 + '0';
	while (ntmp > 0)
	{
		res[i++] = (ntmp % 10) + '0';
		ntmp /= 10;
	}
	res[i] = '\0';
	return (ft_strrev(res));
}
