/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:40:00 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:33:33 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	tmp = (*alst)->next;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	while (tmp)
	{
		del(tmp->content, tmp->content_size);
		*alst = tmp;
		tmp = tmp->next;
		free(*alst);
	}
	*alst = NULL;
}
