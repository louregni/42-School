/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 01:30:34 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/12 12:01:53 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "algorithm.h"
#include "utils.h"

static t_pathnode	*new_pathnode(t_pathnode **prev_next, t_pathnode *prev,
		t_node *node)
{
	t_pathnode		*new;

	if (!(new = ft_memalloc(sizeof(t_pathnode))))
		return (NULL);
	new->node = node;
	new->prev = prev;
	*prev_next = new;
	return (new);
}

static int			way_trace(t_data *data, t_node *node, t_path *path)
{
	t_edge		*edge;
	t_pathnode	*save;

	save = path->pathnode;
	save = new_pathnode(&(path->pathnode), NULL, node);
	edge = node->edge;
	while (edge && edge->flux != 1)
		edge = edge->next;
	if (node == data->sink)
		return (0);
	node = edge->endpoint;
	while (node)
	{
		path->len += 1;
		edge = node->edge;
		save = new_pathnode(&(save->next), save, node);
		while (edge && edge->flux != 1)
			edge = edge->next;
		if (edge == NULL)
			return (-1);
		if (node == data->sink)
			return (0);
		node = edge->endpoint;
	}
	return (-1);
}

int					paths_saver(t_data *data)
{
	t_edge		*edge;
	t_path		*path;

	edge = data->source->edge;
	while (edge)
	{
		if (edge->flux == 1)
		{
			if (!(path = ft_memalloc(sizeof(t_path))))
				return (-1);
			path->next = data->cur_path;
			data->cur_path = path;
			path->len = 1;
			way_trace(data, edge->endpoint, path);
		}
		edge = edge->next;
	}
	return (0);
}
