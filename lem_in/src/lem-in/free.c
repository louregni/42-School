/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:54:20 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/16 17:14:15 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

void	free_pathnode(t_pathnode *node)
{
	t_pathnode *tmp;

	while ((tmp = node))
	{
		node = node->next;
		free(tmp);
	}
}

void	free_nodes(t_node *node)
{
	t_node *tmp;
	t_edge *edge;
	t_edge *tmp_edge;

	while ((tmp = node))
	{
		node = node->next;
		edge = tmp->edge;
		while ((tmp_edge = edge))
		{
			edge = edge->next;
			free(tmp_edge);
		}
		free(tmp->name.name);
		free(tmp);
	}
}

void	free_everything(t_parser *parser)
{
	free_nodes(parser->data.first_node);
}
