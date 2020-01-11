/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:57 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:58 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "common.h"

void	swap(t_container *box, char index)
{
	if (index & 1 && box->a.size > 1)
	{
		swaping(&box->a);
		write(1, "sa\n", 3);
	}
	if (index & 2 && box->b.size > 1)
	{
		swaping(&box->b);
		write(1, "sb\n", 3);
	}
}

void	push(t_container *box, char index)
{
	if (index & 1 && box->b.size > 0)
	{
		push_action(&box->a.start, pop_list(&box->b.start));
		++box->a.size;
		--box->b.size;
		write(1, "pa\n", 3);
	}
	if (index & 2 && box->a.size > 0)
	{
		push_action(&box->b.start, pop_list(&box->a.start));
		++box->b.size;
		--box->a.size;
		write(1, "pb\n", 3);
	}
}

void	rotate(t_container *box, char index)
{
	if (index & 1 && box->a.size > 1)
	{
		box->a.start = box->a.start->next;
		write(1, "ra\n", 3);
	}
	if (index & 2 && box->b.size > 1)
	{
		box->b.start = box->b.start->next;
		write(1, "rb\n", 3);
	}
}

void	revrotate(t_container *box, char index)
{
	if (index & 1 && box->a.size > 1)
	{
		box->a.start = box->a.start->prev;
		write(1, "rra\n", 4);
	}
	if (index & 2 && box->b.size > 1)
	{
		box->b.start = box->b.start->prev;
		write(1, "rrb\n", 4);
	}
}
