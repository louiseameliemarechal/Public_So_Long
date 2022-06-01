/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:09:29 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/07 15:28:42 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*e;

	if (lst == NULL)
		return (NULL);
	l = 0;
	while (lst)
	{	
		e = ft_lstnew(f(lst->content));
		if (e == NULL)
		{	
			ft_lstclear(&e, del);
			return (NULL);
		}
		ft_lstadd_back(&l, e);
		lst = lst->next;
	}
	return (l);
}
