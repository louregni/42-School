/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:51:02 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:51:05 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "utils.h"
#include "find.h"

int	fix_link(t_parser *parser, t_name *room)
{
	t_link	first_room;
	t_link	second_room;
	t_node	*first_node;
	t_node	*second_node;

	ft_memcpy(first_room.name, room->name, room->size);
	free(room->name);
	first_room.size = room->size;
	if (!(first_node = check_room(parser, &first_room)))
		return (-1);
	if (get_name(&parser->reader, &second_room, '\n'))
		return (-1);
	if (!(second_node = check_room(parser, &second_room)))
		return (-1);
	if (first_node == second_node)
		return (-1);
	if (link_two_nodes(first_node, second_node))
		return (-1);
	parser->target = EDGE;
	return (0);
}

int	get_link(t_parser *parser)
{
	t_link	first_room;
	t_link	second_room;
	t_node	*first_node;
	t_node	*second_node;

	if (get_name(&parser->reader, &first_room, '-'))
		return (-1);
	if (!(first_node = check_room(parser, &first_room)))
		return (-1);
	if (get_name(&parser->reader, &second_room, '\n'))
		return (-1);
	if (!(second_node = check_room(parser, &second_room)))
		return (-1);
	if (first_node == second_node)
		return (-1);
	if (link_two_nodes(first_node, second_node))
		return (-1);
	return (0);
}
