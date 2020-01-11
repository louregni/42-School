/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:42:06 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:42:07 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int				have_between(t_stack *x, unsigned int high, unsigned int low)
{
	t_list			*tmp;
	unsigned int	i;

	if (!x->size)
		return (0);
	tmp = x->start;
	i = 0;
	while (i < x->size)
	{
		if (low <= tmp->index && tmp->index <= high)
			return (1);
		++i;
		tmp = tmp->next;
	}
	return (0);
}

unsigned int	split_a(t_container *box, unsigned int high, unsigned int low)
{
	unsigned int iter;

	iter = 0;
	while (have_between(&(box->a), high, low))
	{
		if (box->a.start->index <= high)
			push(box, STACK_B);
		else
		{
			rotate(box, STACK_A);
			++iter;
		}
	}
	return (iter);
}

unsigned int	split(t_container *box, unsigned int high, unsigned int low)
{
	unsigned int mid;

	mid = (high + low) / 2;
	while (have_between(&(box->b), high, mid))
	{
		if (opti_easy(box) == mid)
			++mid;
		else
		{
			if (box->b.size && box->b.start->index < mid)
				rotate(box, STACK_B);
			else
				push(box, STACK_A);
		}
	}
	return (mid);
}

void			sort_b_small(t_container *box)
{
	if (box->b.size == 4)
	{
		opti_easy(box);
		if (box->b.size == 4)
		{
			revrotate(box, STACK_B);
			opti_easy(box);
			(box->b.size == 4) ? revrotate(box, STACK_B) : 42;
			(box->b.size == 4) ? opti_easy(box) : 42;
		}
	}
	if (box->b.size == 3)
	{
		opti_easy(box);
		(box->b.size == 3) ? revrotate(box, STACK_B) : 42;
		(box->b.size == 3) ? opti_easy(box) : 42;
	}
	(box->b.size == 2) ? opti_easy(box) : 42;
	(box->b.size == 1) ? opti_easy(box) : 42;
}

/*
** .....  |  Reduce list in recursive     ┌───┐
** :   :  |         ──────────────────\   │ B │  With A < B
** ┌───┐  |  ┌───┐   then if size < 4  }  └─┬─┘  and A list
** │ B │  |  │ A │  ──────────────────/    /A\   sorted asc
** └───┘  |  └───┘  stack sorted list     /___\
*/

unsigned int	sort_recurse(t_container *box,
	unsigned int high, unsigned int low, int end)
{
	unsigned int	counter;
	unsigned int	pivot;

	if (end == 1)
		while (box->floor <= box->a.start->index && box->a.start->index <= high)
		{
			low = box->floor;
			opti_easy(box);
			if (low == box->floor)
				push(box, STACK_B);
		}
	if (box->b.size > 4)
	{
		pivot = split(box, high, low);
		counter = sort_recurse(box, pivot, low, 0);
		sort_recurse(box, high, pivot + counter, 1);
	}
	counter = box->b.size;
	sort_b_small(box);
	return (counter);
}
