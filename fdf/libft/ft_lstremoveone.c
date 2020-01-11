/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:54:20 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/12 13:30:21 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremoveone(t_list **lst, void *content, size_t content_size,
						void (*del)(void *, size_t))
{
	t_list	*prev;
	t_list	*next;

	prev = *lst;
	if (content_size == (*lst)->content_size &&
		ft_memcmp((*lst)->content, content, content_size) == 0)
	{
		*lst = (*lst)->next;
		ft_lstdelone(&prev, del);
		return ;
	}
	next = prev->next;
	while (next)
	{
		if (content_size == next->content_size &&
			ft_memcmp(content, next->content, content_size) == 0)
		{
			prev->next = next->next;
			ft_lstdelone(&next, del);
			return ;
		}
		prev = next;
		next = next->next;
	}
}
