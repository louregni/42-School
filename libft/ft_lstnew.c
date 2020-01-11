/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:23:23 by louregni          #+#    #+#             */
/*   Updated: 2018/11/19 17:51:52 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	if (!(ptr = (t_list *)malloc(sizeof(t_list))))
		return ((t_list *)NULL);
	if (content == NULL || content_size == 0)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
		ptr->next = NULL;
		return (ptr);
	}
	if (!(ptr->content = ft_memdup((char *)content, content_size)))
	{
		free(ptr);
		return (NULL);
	}
	ptr->next = NULL;
	ptr->content_size = content_size;
	return (ptr);
}
