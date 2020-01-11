/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:34:07 by louregni          #+#    #+#             */
/*   Updated: 2018/11/20 16:08:26 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		lst_clear(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if (lst == NULL || f == NULL)
		return ((void *)NULL);
	if (!(new = f(lst)))
		return ((void *)NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = f(lst)))
		{
			ft_lstdel(&start, &lst_clear);
			return ((void *)NULL);
		}
		lst = lst->next;
		new = new->next;
	}
	new->next = NULL;
	return (start);
}
