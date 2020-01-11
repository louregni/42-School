/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:40:59 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:00 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	swap(t_container *box, char index)
{
	if (index & 1 && box->a.size > 1)
		swaping(&box->a);
	if (index & 2 && box->b.size > 1)
		swaping(&box->b);
}

void	push(t_container *box, char index)
{
	if (index & 1 && box->b.size > 0)
	{
		push_action(&box->a.start, pop_list(&box->b.start));
		++box->a.size;
		--box->b.size;
	}
	if (index & 2 && box->a.size > 0)
	{
		push_action(&box->b.start, pop_list(&box->a.start));
		++box->b.size;
		--box->a.size;
	}
}

void	rotate(t_container *box, char index)
{
	if (index & 1 && box->a.size > 1)
		box->a.start = box->a.start->next;
	if (index & 2 && box->b.size > 1)
		box->b.start = box->b.start->next;
}

void	revrotate(t_container *box, char index)
{
	if (index & 1 && box->a.size > 1)
		box->a.start = box->a.start->prev;
	if (index & 2 && box->b.size > 1)
		box->b.start = box->b.start->prev;
}
