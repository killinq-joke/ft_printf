/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:45:36 by ztouzri           #+#    #+#             */
/*   Updated: 2021/01/22 13:20:31 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*desttmp;
	unsigned char	*srctmp;

	srctmp = (unsigned char*)src;
	desttmp = (unsigned char*)dest;
	i = 0;
	while (i < n && (dest || src))
	{
		desttmp[i] = srctmp[i];
		i++;
	}
	return (dest);
}
