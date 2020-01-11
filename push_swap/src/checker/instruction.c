/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:22 by louregni          #+#    #+#             */
/*   Updated: 2019/07/18 01:21:07 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "common.h"
#include "visual.h"

void	set_action(t_action *action, int fc, int index)
{
	action->fc = fc;
	action->index = index;
}

int		check_three(t_action *action, char *buf)
{
	if (ft_diff(buf, "sa\n", 3))
		set_action(action, 0, 1);
	else if (ft_diff(buf, "sb\n", 3))
		set_action(action, 0, 2);
	else if (ft_diff(buf, "ss\n", 3))
		set_action(action, 0, 3);
	else if (ft_diff(buf, "pa\n", 3))
		set_action(action, 1, 1);
	else if (ft_diff(buf, "pb\n", 3))
		set_action(action, 1, 2);
	else if (ft_diff(buf, "ra\n", 3))
		set_action(action, 2, 1);
	else if (ft_diff(buf, "rb\n", 3))
		set_action(action, 2, 2);
	else if (ft_diff(buf, "rr\n", 3))
		set_action(action, 2, 3);
	else if (ft_diff(buf, "rr", 2))
		return (2);
	else
		return (0);
	return (1);
}

int		check_four(t_action *action, char *buf)
{
	if (ft_diff(buf, "rra\n", 4))
		set_action(action, 3, 1);
	else if (ft_diff(buf, "rrb\n", 4))
		set_action(action, 3, 2);
	else if (ft_diff(buf, "rrr\n", 4))
		set_action(action, 3, 3);
	else
		return (0);
	return (1);
}

int		bind_action(t_action *action)
{
	char	buf[4];
	int		ret;

	while ((ret = read(0, buf, 3)) == -1)
		;
	if (!ret)
		return (0);
	if ((ret = check_three(action, buf)) == 1)
		return (1);
	else if (ret == 2)
	{
		ret = read(0, buf + 3, 1);
		if (ret < 1)
			return (-1);
		if (check_four(action, buf))
			return (1);
	}
	return (-1);
}
