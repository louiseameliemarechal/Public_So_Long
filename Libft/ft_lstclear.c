/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:18:36 by lmarecha          #+#    #+#             */
/*   Updated: 2021/12/07 15:27:52 by lmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;
	t_list	*temp;

	l = *lst;
	if (l == NULL)
		return ;
	while (l)
	{
		temp = l->next;
		del(l->content);
		free(l);
		l = temp;
	}
	*lst = NULL;
}
