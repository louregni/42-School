/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:51:11 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:51:12 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "utils.h"

int	get_source(t_parser *parser, unsigned int size)
{
	update_reader(&parser->reader, size);
	if (parser->data.source)
		return (0);
	if (get_node(parser))
		return (-1);
	if (*parser->tmp->name.name == 'L' || *parser->tmp->name.name == '#'
		|| *parser->tmp->name.name == '-' || *parser->tmp->name.name == ' ')
		return (-1);
	parser->data.source = parser->tmp;
	parser->tmp = 0;
	return (0);
}

int	get_sink(t_parser *parser, unsigned int size)
{
	if (parser->data.sink)
		return (0);
	update_reader(&parser->reader, size);
	if (get_node(parser))
		return (-1);
	if (*parser->tmp->name.name == 'L' || *parser->tmp->name.name == '#'
		|| *parser->tmp->name.name == '-' || *parser->tmp->name.name == ' ')
		return (-1);
	parser->data.sink = parser->tmp;
	parser->tmp = 0;
	return (0);
}

int	create_node(t_parser *parser)
{
	t_node *node;

	if (!(node = malloc(sizeof(*node))))
		return (-1);
	ft_bzero(node, sizeof(*node));
	parser->tmp = node;
	return (0);
}
