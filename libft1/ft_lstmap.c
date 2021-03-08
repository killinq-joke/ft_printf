/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztouzri <ztouzri@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:56:04 by ztouzri           #+#    #+#             */
/*   Updated: 2021/02/09 12:28:21 by ztouzri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *mapped;
	t_list *new;

	mapped = NULL;
	if (f && del)
	{
		while (lst)
		{
			if (!(new = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&mapped, del);
				return (NULL);
			}
			ft_lstadd_back(&mapped, new);
			lst = lst->next;
		}
		return (mapped);
	}
	return (NULL);
}
