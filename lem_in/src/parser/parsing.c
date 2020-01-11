/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:51:17 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:51:18 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "utils.h"

/*
** Thoses little function are the result of the parsing at the beginning of
** lines.
*/

static const t_command	g_command[] = {
	(t_command){
		.name = "start\n",
		.size = 6,
		.exec = get_source,
	},
	(t_command){
		.name = "end\n",
		.size = 4,
		.exec = get_sink,
	},
};

inline int				read_entry(t_read *reader)
{
	while ((reader->size = read(0, reader->buf, READ_SIZE)) < 0)
		;
	if (!reader->size)
		return (-1);
	reader->ptr = reader->buf;
	write(1, reader->ptr, reader->size);
	return (0);
}

inline void				update_reader(t_read *reader, unsigned char size)
{
	reader->size -= size;
	reader->ptr += size;
}

int						is_comment(t_parser *parser)
{
	--parser->reader.size;
	++parser->reader.ptr;
	if (find_newline(&parser->reader))
		return (-1);
	return (0);
}

static int				is_command(t_parser *parser)
{
	unsigned int	i;
	unsigned int	save;

	i = 2;
	if (!parser->reader.size && read_entry(&parser->reader))
		return (-1);
	while (i--)
	{
		if (parser->reader.size >= g_command[i].size
				&& !compare(g_command[i].name, parser->reader.ptr,
					g_command[i].size))
			return (g_command[i].exec(parser, g_command[i].size));
		if (compare(g_command[i].name, parser->reader.ptr,
					g_command[i].size))
			continue;
		save = parser->reader.size;
		if (!parser->reader.size && read_entry(&parser->reader))
			return (-1);
		if ((int)(g_command[i].size - save) > parser->reader.size)
			return (-2);
		if (!compare((g_command[i].name + save), parser->reader.ptr,
					(g_command[i].size - save)))
			return (g_command[i].exec(parser, (g_command[i].size - save)));
	}
	return (-2);
}

int						is_diez(t_parser *parser)
{
	int				ret;

	--parser->reader.size;
	++parser->reader.ptr;
	if (!parser->reader.size && read_entry(&parser->reader))
		return (-1);
	if (*parser->reader.ptr != '#')
		return (is_comment(parser));
	--parser->reader.size;
	++parser->reader.ptr;
	if ((ret = is_command(parser)) == -2)
	{
		if (find_newline(&parser->reader))
			return (-1);
		return (0);
	}
	return (ret);
}
