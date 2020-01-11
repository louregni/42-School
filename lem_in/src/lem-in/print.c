/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:49:47 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:49:47 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include "print.h"

static inline void		merge_path(t_data *data, t_path **target)
{
	t_path *save;

	save = *target;
	free_pathnode((*target)->pathnode);
	if (*target == data->cur_path)
	{
		data->cur_path = (*target)->next;
		free(*target);
		*target = data->cur_path;
		return ;
	}
	save = data->cur_path;
	while (save->next != *target)
		save = save->next;
	save->next = (*target)->next;
	free(*target);
	*target = save->next;
}

static inline void		init_ant(t_data *data, t_path *path, t_pathnode *node)
{
	unsigned int nbr;

	nbr = data->ants;
	node->id.name[11] = '-';
	node->id.ptr = &node->id.name[10];
	node->id.size = 2;
	while (nbr)
	{
		*node->id.ptr = (nbr % 10) + '0';
		nbr /= 10;
		--node->id.ptr;
		++node->id.size;
	}
	*node->id.ptr = 'L';
	--data->ants;
	--path->ants_to_send;
}

static inline void		converge_ants(t_pathnode *node,
			int *update, unsigned int flags)
{
	node = node->prev;
	while (node)
	{
		if (node->id.ptr)
		{
			if (flags & COLOR)
			{
				if (!node->next->next)
					leave_color(&node->id, &node->next->node->name);
				else
					classic(&node->id, &node->next->node->name);
			}
			else
				print_ant(&node->id, &node->next->node->name);
			node->next->id = node->id;
			node->next->id.ptr = node->next->id.name
				+ (12 - node->next->id.size);
			*update = 1;
		}
		node->id.ptr = 0;
		node = node->prev;
	}
}

static int				update(t_data *data, t_path *path, unsigned int flags)
{
	t_pathnode	*node;
	int			update;

	node = path->pathnode;
	update = 0;
	while (node->next)
		node = node->next;
	if (!node->prev && data->ants)
	{
		init_ant(data, path, node);
		print_leave(&node->id, &node->node->name, flags);
		return (1);
	}
	converge_ants(node, &update, flags);
	if (data->ants && path->ants_to_send)
	{
		init_ant(data, path, path->pathnode);
		print_enter(&path->pathnode->id, &path->pathnode->node->name, flags);
		return (1);
	}
	return (update);
}

unsigned int			print_anthill(t_data *data, unsigned int flags)
{
	t_path			*path;
	unsigned int	ret;
	unsigned int	nb_lines;
	unsigned int	move;

	ret = 1;
	nb_lines = 0;
	while (ret)
	{
		path = data->cur_path;
		ret = 0;
		while (path)
		{
			move = update(data, path, flags);
			ret += move;
			if (!move && !path->ants_to_send)
				merge_path(data, &path);
			else
				path = path->next;
		}
		if (ret && ++nb_lines)
			write(1, "\n", 1);
	}
	return (nb_lines);
}
