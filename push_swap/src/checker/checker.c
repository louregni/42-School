/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:06 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:08 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "common.h"
#include "visual.h"

static int	checker(t_container *box, t_visual *visual)
{
	while (visual->current->next->next)
	{
		visual->current = visual->current->next;
		visual->action[visual->current->fc](box, visual->current->index);
	}
	if (box->b.size || !is_sort(box->a.start))
	{
		write(1, "KO\n", 3);
		return (1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_container		box;
	t_visual		visual;
	int				ret;

	if (ac < 2)
		return (0);
	ret = 0;
	if (!check_visual(&visual, ac, av))
		return (0);
	if (!(ret = initializer(&box, &visual, ac, av)))
	{
		if (visual.enable)
			ret = visualizer(&box, &visual);
		else
			ret = checker(&box, &visual);
	}
	del_list(&box, &visual);
	if (ret)
		return (0);
	write(1, "OK\n", 3);
	return (0);
}
