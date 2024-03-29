/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:58:17 by ztouzri           #+#    #+#             */
/*   Updated: 2021/01/23 14:29:09 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_twoinstances(const char *s, int c)
{
	int i;
	int instances;

	i = 0;
	instances = 0;
	while (s[i])
	{
		if (s[i] == c)
			instances++;
		if (instances == 2)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && ft_twoinstances(&s[i], c))
		i++;
	return (ft_strchr(&s[i], c));
}
