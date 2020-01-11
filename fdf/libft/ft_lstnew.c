/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:02:00 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/09 13:46:58 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->next = NULL;
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	if (!(new->content = malloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	return (new);
}
