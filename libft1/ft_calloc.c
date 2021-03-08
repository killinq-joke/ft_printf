/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:42:18 by ztouzri           #+#    #+#             */
/*   Updated: 2021/01/21 14:43:05 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	space;
	void	*ptr;

	space = count * size;
	if (!(ptr = malloc(space)))
		return (NULL);
	ft_bzero(ptr, space);
	return (ptr);
}
