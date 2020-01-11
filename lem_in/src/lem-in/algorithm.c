/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:00:12 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/18 12:12:56 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "algorithm.h"
#include "utils.h"

int		add_step(t_data *data, t_node *node, t_edge *prev_edge, int dist)
{
	t_step		*new_step;
	int			mode;

	mode = 0;
	if (dist < 0)
		mode = 1;
	if (dist < 0)
		dist = -dist;
	if (!(new_step = ft_memalloc(sizeof(t_step))))
		return (-1);
	new_step->node = node;
	new_step->mode = mode;
	new_step->prev_step = data->current_step;
	new_step->prev_edge = prev_edge;
	new_step->dist = dist;
	if (data->first_step == NULL)
	{
		data->first_step = new_step;
		data->current_step = new_step;
	}
	else
		data->last_step->next = new_step;
	data->last_step = new_step;
	return (0);
}

int		step_read(t_data *data, t_step *step, t_node *node, t_edge *edge)
{
	while (edge)
	{
		if (edge->endpoint->dist || edge->flux == 1)
			;
		else if (step->mode)
		{
			if (edge->flux == -1)
			{
				node->dist = step->dist;
				add_step(data, edge->endpoint, edge, node->dist + 1);
			}
		}
		else
		{
			if (edge->endpoint == data->sink)
				return (trace_path(data, data->current_step, edge));
			node->dist = step->dist;
			if (node->crossed == 0 && edge->endpoint->crossed == 1)
				add_step(data, edge->endpoint, edge, -(node->dist + 1));
			else
				add_step(data, edge->endpoint, edge, node->dist + 1);
		}
		edge = edge->next;
	}
	return (0);
}

void	path_cleaner(t_data *data)
{
	t_node *list;

	list = data->first_node;
	while (list)
	{
		list->dist = 0;
		list = list->next;
	}
}

int		new_path(t_data *data)
{
	path_cleaner(data);
	add_step(data, data->source, NULL, 1);
	data->source->dist = 1;
	while (data->current_step)
	{
		if (step_read(data, data->current_step, data->current_step->node,
					data->current_step->node->edge))
			return (1);
		data->current_step = data->current_step->next;
	}
	return (0);
}

t_path	*algorithm(t_data *data)
{
	while (new_path(data))
	{
		paths_saver(data);
		free_steps(data);
		data->cur_path_turns = turns_count(data, data->cur_path);
		if (data->saved_path
				&& (data->saved_path_turns <= data->cur_path_turns))
		{
			paths_free(data->cur_path);
			data->cur_path = NULL;
		}
		else
		{
			paths_free(data->saved_path);
			data->saved_path = data->cur_path;
			data->saved_path_turns = data->cur_path_turns;
			data->cur_path = NULL;
		}
	}
	free_steps(data);
	return (data->saved_path);
}
