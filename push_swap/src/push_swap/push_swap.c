/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:42:03 by louregni          #+#    #+#             */
/*   Updated: 2019/07/18 01:09:09 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "common.h"

static void	get_soluce(unsigned long long order)
{
	int				i;
	const t_soluce	soluces[33] = {
		{0x1023, "sa\n"}, {0x1032, "pb\npb\nss\npa\npa\n"}, {0x210, "ra\nsa\n"},
		{0x0321, "ra\nsa\nrra\nrra\nsa\n"}, {0x2103, "rra\nsa\nrra\nrra\nsa\n"},
		{0x1230, "rra\n"}, {0x2031, "sa\nrra\nsa\n"}, {0x0213, "ra\nsa\nrra\n"},
		{0x2130, "sa\nrra\n"}, {0x1302, "rra\nsa\nrra\n"}, {0x2301, "ra\nra\n"},
		{0x2310, "rra\nrra\nsa\n"}, {0x3210, "sa\nrra\nrra\nsa\n"}, {0x012, ""},
		{0x0132, "ra\nsa\nrra\nsa\nra\n"}, {0x3120, "rra\nsa\nra\n"}, {0x0, ""},
		{0x2013, "rra\nsa\nrra\nrra\n"}, {0x3201, "sa\nra\nra\n"}, {0x0123, ""},
		{0x0312, "sa\nra\n"}, {0x120, "rra\n"}, {0x201, "ra\n"}, {0x10, "sa\n"},
		{0x3021, "ra\npb\nsa\npa\n"}, {0x1320, "sa\nrra\nsa\nra\n"}, {0x01, ""},
		{0x1203, "ra\nra\nsa\nra\n"}, {0x0231, "rra\nsa\n"}, {0x3012, "ra\n"},
		{0x021, "ra\nsa\nrra\n"}, {0x102, "sa\n"}, {0x3102, "ra\nsa\n"},
	};

	i = -1;
	while (++i < 33 && soluces[i].order != order)
		;
	write(1, soluces[i].soluce, ft_strlen(soluces[i].soluce));
}

static void	static_sort(t_list *tab, int size, int offset)
{
	int					i;
	unsigned long long	order;

	order = 0;
	i = -1;
	while (++i < size)
	{
		order = (order << 4) | (tab->index - offset);
		tab = tab->next;
	}
	get_soluce(order);
}

static void	extract_static_sort(t_container *box)
{
	if (box->a.start->next->next->index == 0)
		rotate(box, STACK_A);
	if (box->a.start->next->index == 0)
		rotate(box, STACK_A);
	if (box->a.start->prev->prev->index == 0)
		revrotate(box, STACK_A);
	if (box->a.start->prev->index == 0)
		revrotate(box, STACK_A);
	if (box->a.start->index == 0)
		push(box, STACK_B);
	static_sort(box->a.start, 4, 1);
	push(box, STACK_A);
}

/*
** ┌───┐        ┌───┐        ┌───┐ |  Reduce by interating        ┌───┐
** │ A │  ──\   │ B │  ──\   │ C │ |        ──────────────────\   │ C │  With
** ├───┤     }  └─┬─┘     }  └─┬─┘ | ┌───┐                     }  └─┬─┘  A < B
** │ B │  ──/    /A\   ──/    /A\  | │ B │  ──────────────────/    /A\   B < C
** └───┘        /___\        /___\ | └───┘                        / B \
**                                                               /_____\
*/

static void	sort(t_container *box)
{
	unsigned int	i;

	split_a(box, box->size / 2, box->pivot);
	while (box->a.start->index != 0 || box->b.size)
	{
		sort_recurse(box, (box->size + box->pivot) / 2, box->pivot, 0);
		box->pivot = (box->size + box->pivot) / 2;
		i = split_a(box, (box->size + box->pivot) / 2, box->pivot + 1);
		if (i == 0)
			opti_easy(box);
		while (i--)
			revrotate(box, STACK_A);
	}
}

int			main(int ac, char **av)
{
	t_container	box;

	if (create_list(&box, ac, av) && !is_sort(box.a.start) && box.a.size > 1)
	{
		box.size = box.a.size;
		if (box.size > 5)
			sort(&box);
		else if (box.size == 5)
			extract_static_sort(&box);
		else
			static_sort((box.a.start), box.size, 0);
	}
	del(box.a.start);
	del(box.b.start);
	return (0);
}
