/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:45:15 by ztouzri           #+#    #+#             */
/*   Updated: 2021/01/22 13:32:00 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1tmp;
	unsigned char	*s2tmp;

	if (n == 0)
		return (0);
	s1tmp = (unsigned char*)s1;
	s2tmp = (unsigned char*)s2;
	while (n > 1 && *s2tmp == *s1tmp)
	{
		s2tmp++;
		s1tmp++;
		n--;
	}
	return (*s1tmp - *s2tmp);
}
