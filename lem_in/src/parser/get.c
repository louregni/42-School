/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:50:40 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:50:40 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "parser.h"
#include "find.h"

int	get_int(t_read *reader, unsigned int *number, unsigned char sep)
{
	long long	tmp;

	tmp = 0;
	while (1)
	{
		while (reader->size && (*reader->ptr >= '0' && *reader->ptr <= '9'))
		{
			tmp = tmp * 10 + *reader->ptr - '0';
			if (tmp > INT_MAX)
				return (-1);
			update_reader(reader, 1);
		}
		if (!reader->size)
		{
			if (read_entry(reader))
				return (-1);
			continue ;
		}
		if (reader->size && *reader->ptr != sep)
			return (-1);
		*number = tmp;
		update_reader(reader, 1);
		return (0);
	}
}

int	set_node(t_parser *parser, t_name *name)
{
	int			ret;

	ret = get_node_name(&parser->reader, name);
	if (ret == 1)
		return (fix_link(parser, name));
	else if (ret)
		return (-1);
	if (create_node(parser))
		return (-1);
	parser->tmp->name = *name;
	if (check_exists(parser))
		return (-1);
	if (get_int(&parser->reader, &parser->tmp->cord.x, ' '))
		return (-1);
	if (get_int(&parser->reader, &parser->tmp->cord.y, '\n'))
		return (-1);
	parser->tmp->next = parser->array[*parser->tmp->name.name];
	parser->array[*parser->tmp->name.name] = parser->tmp;
	return (0);
}

int	get_node(t_parser *parser)
{
	t_name		name;

	name.name = 0;
	if (set_node(parser, &name))
	{
		if (parser->tmp)
		{
			free(parser->tmp);
			parser->tmp = 0;
		}
		if (name.name)
			free(name.name);
		return (-1);
	}
	return (0);
}

int	get_nb_ant(t_parser *parser)
{
	if (get_int(&parser->reader, &parser->data.ants, '\n'))
		return (-1);
	parser->target = NODE;
	return (0);
}
