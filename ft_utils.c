/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:58:13 by ztouzri           #+#    #+#             */
/*   Updated: 2021/03/05 09:08:53 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_strrev(char *str)
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

int		itoa_converter(long long nbr, char *result, char *base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		result[i++] = base[(nbr % ft_strlen(base))];
	while (nbr > 0)
	{
		result[i++] = base[(nbr % ft_strlen(base))];
		nbr /= ft_strlen(base);
	}
	return (i);
}

int		ztoa_converter(unsigned long long nbr, char *result, char *base)
{
	int	i;

	i = 0;
	if (nbr == 0)
		result[i++] = base[(nbr % ft_strlen(base))];
	while (nbr > 0)
	{
		result[i++] = base[(nbr % ft_strlen(base))];
		nbr /= ft_strlen(base);
	}
	return (i);
}

char	*ft_itoa_base(long nbr, char *base)
{
	char	*result;
	int		i;
	int		sign;

	sign = 0;
	if (!(result = malloc(sizeof(char) * 50)))
		return (NULL);
	if (nbr < 0)
	{
		sign = 1;
		nbr *= -1;
	}
	i = itoa_converter(nbr, result, base);
	if (sign)
		result[i++] = '-';
	result[i] = '\0';
	result = ft_strrev(result);
	result[i] = '\0';
	return (result);
}

char	*ft_ztoa_base(unsigned long long nbr, char *base)
{
	char	*result;
	int		i;

	if (!(result = malloc(sizeof(char) * 50)))
		return (NULL);
	i = ztoa_converter(nbr, result, base);
	result[i] = '\0';
	result = ft_strrev(result);
	result[i] = '\0';
	return (result);
}
