/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:57:50 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/23 15:57:30 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*next;

	if (alst == NULL)
		return ;
	ptr = *alst;
	*alst = NULL;
	while (ptr)
	{
		next = ptr->next;
		ft_lstdelone(&ptr, del);
		ptr = next;
	}
}
