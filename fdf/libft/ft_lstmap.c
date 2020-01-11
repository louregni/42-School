/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:37:09 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/15 13:40:15 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_lstdelcontent(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*ptr;
	t_list	*prev;

	if (lst == NULL)
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	ptr = new;
	lst = lst->next;
	while (lst)
	{
		prev = ptr;
		if (!(ptr = f(lst)))
		{
			ft_lstdel(&new, &ft_lstdelcontent);
			return (NULL);
		}
		prev->next = ptr;
		ptr->next = NULL;
		lst = lst->next;
	}
	ptr->next = NULL;
	return (new);
}
