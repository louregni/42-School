/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:49:41 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:49:43 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "utils.h"
#include "print.h"
#include "parsing.h"

/*
** The parser function will parse all inputs in the Standard input.
** It will init all chained list about anthill.
*/

int					wrong_case(void)
{
	return (-1);
}

static int			parse(t_parser *parser)
{
	while (1)
	{
		if (!parser->reader.size && read_entry(&parser->reader))
			return (-1);
		if (g_parser_modes[parser->target].parser[*parser->reader.ptr](parser))
			return (-1);
	}
	return (0);
}

static void			init_parser(t_parser *parser)
{
	parser->target = NB_ANT;
	parser->reader.size = 0;
	ft_bzero(&parser->data, sizeof(parser->data));
	ft_bzero(parser->array, sizeof(parser->array));
}

static inline void	create_list(t_parser *parser)
{
	unsigned int	i;
	t_node			*tmp;

	i = 127;
	while (i > ' ' && !parser->array[i])
		--i;
	parser->tmp = parser->array[i];
	tmp = parser->array[i];
	while (i > ' ')
	{
		if (parser->array[i])
		{
			tmp = parser->array[i];
			while (tmp->next)
				tmp = tmp->next;
			--i;
			while (i > ' ' && !parser->array[i])
				--i;
			tmp->next = parser->array[i];
		}
	}
}

int					parsing(t_parser *parser, t_bonus *bonus)
{
	init_parser(parser);
	parse(parser);
	create_list(parser);
	if (check_info(parser, bonus))
		return (-1);
	parser->data.first_node = parser->tmp;
	return (0);
}
