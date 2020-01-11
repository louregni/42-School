/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:42:01 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:42:01 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

unsigned int	opti_easy(t_container *box)
{
	unsigned int target;

	target = box->floor;
	if (box->b.size >= 3 && box->b.start->prev->index == target)
		revrotate(box, STACK_B);
	if (box->b.size == 2 && box->b.start->prev->index == target)
		push(box, STACK_A);
	if (box->b.size >= 1 && box->b.start->index == target)
		push(box, STACK_A);
	if (box->a.size >= 1 && box->a.start->index == target)
		rotate(box, STACK_A);
	if (box->a.size >= 2 && box->a.start->prev->index == target)
		++box->floor;
	return (target);
}
