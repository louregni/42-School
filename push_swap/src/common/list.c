/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:46 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:47 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

void	push_list(t_list **start, t_list *elem)
{
	if (!(*start))
	{
		*start = elem;
		elem->next = elem;
		elem->prev = elem;
		return ;
	}
	elem->prev = (*start)->prev;
	(*start)->prev->next = elem;
	(*start)->prev = elem;
	elem->next = (*start);
}

void	del(t_list *start)
{
	t_list	*tmp;

	if (start)
	{
		if (start->prev)
			start->prev->next = 0;
		tmp = start;
		while ((start = tmp))
		{
			tmp = start->next;
			free(start);
		}
	}
}

t_list	*pop_list(t_list **start)
{
	t_list *tmp;

	tmp = *start;
	if ((*start)->next == *start)
		*start = (void*)0;
	else
	{
		*start = (*start)->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	return (tmp);
}

void	push_action(t_list **start, t_list *elem)
{
	if (!(*start))
	{
		*start = elem;
		elem->next = elem;
		elem->prev = elem;
		return ;
	}
	elem->prev = (*start)->prev;
	(*start)->prev->next = elem;
	elem->next = *start;
	(*start)->prev = elem;
	*start = elem;
}

void	swaping(t_stack *s)
{
	t_list *tmp;

	tmp = s->start->next;
	if (s->size == 2)
	{
		tmp->next = s->start;
		tmp->prev = s->start;
		s->start->next = tmp;
		s->start->prev = tmp;
		s->start = tmp;
		return ;
	}
	s->start->prev->next = tmp;
	tmp->next->prev = s->start;
	tmp->prev = s->start->prev;
	s->start->next = tmp->next;
	tmp->next = s->start;
	s->start->prev = tmp;
	s->start = tmp;
}
