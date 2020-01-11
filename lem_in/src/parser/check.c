/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:54:21 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:54:21 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "utils.h"
#include "print.h"

int						check_exists(t_parser *parser)
{
	t_node		*node;

	node = parser->array[*parser->tmp->name.name];
	while (node)
	{
		if (node->name.size != parser->tmp->name.size)
		{
			node = node->next;
			continue ;
		}
		else if (!compare(node->name.name, parser->tmp->name.name,
					parser->tmp->name.size))
			return (-1);
		node = node->next;
	}
	return (0);
}

t_node					*check_room(t_parser *parser, t_link *name)
{
	t_node			*tmp;

	tmp = parser->array[*name->name];
	while (tmp)
		if ((name->size != tmp->name.size)
				|| compare(name->name, tmp->name.name, name->size))
			tmp = tmp->next;
		else
			return (tmp);
	return (0);
}

static unsigned int		check_error(t_parser *parser)
{
	unsigned int	missing;

	missing = 0;
	if (!parser->data.ants)
		missing |= ANTS;
	if (!parser->data.source)
		missing |= SOURCE;
	if (!parser->data.sink)
		missing |= SINK;
	if (!parser->data.source || !(parser->data.source->edge))
		missing |= SOURCE_EDGE;
	if (!parser->data.sink || !(parser->data.sink->edge))
		missing |= SINK_EDGE;
	return (missing);
}

int						check_info(t_parser *parser, t_bonus *bonus)
{
	unsigned int	missing;

	missing = check_error(parser);
	bonus->missing = missing;
	return (missing);
}
