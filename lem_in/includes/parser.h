/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 04:37:59 by louregni          #+#    #+#             */
/*   Updated: 2019/12/16 04:38:00 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define READ_SIZE 4096
# define WORD_SIZE 38
# include <stddef.h>
# include "structures.h"

/*
**=============================================================================
**								Constant structures
**=============================================================================
*/

typedef struct			s_parser_line
{
	int					(*parser[256])();
}						t_parser_line;

typedef struct			s_arg
{
	int					size;
	char				*name;
}						t_arg;

typedef struct			s_command
{
	int					(*exec)();
	int					size;
	char				*name;
}						t_command;

/*
**=============================================================================
**								Enum structures
**=============================================================================
*/

typedef enum			e_target
{
	NB_ANT,
	NODE,
	EDGE,
	TARGET_MAX,
}						t_target;

/*
**=============================================================================
**								Basic structures
**=============================================================================
*/

typedef struct			s_read
{
	unsigned char		*ptr;
	int					size;
	unsigned char		buf[READ_SIZE];
}						t_read;

typedef struct			s_link
{
	unsigned char		name[WORD_SIZE];
	unsigned int		size;
}						t_link;

typedef struct			s_parser
{
	t_read				reader;
	t_target			target;
	t_node				*array[128];
	t_node				*tmp;
	t_data				data;
}						t_parser;

/*
**=============================================================================
**								Functions prototypes
**=============================================================================
*/

/*
** Functions used in state machine to get elements
*/

int						get_link(t_parser *parser);
int						is_diez(t_parser *parser);
int						get_node(t_parser *parser);
int						get_nb_ant(t_parser *parser);
int						is_comment(t_parser *parser);

/*
** F
*/

int						get_sink(t_parser *parser, unsigned int size);
int						get_source(t_parser *parser, unsigned int size);
int						read_entry(t_read *reader);
int						find_newline(t_read *reader);
void					update_reader(t_read *reader, unsigned char size);
int						check_exists(t_parser *parser);
int						fix_link(t_parser *parser, t_name *room);
int						get_node_name(t_read *reader, t_name *name);
int						create_node(t_parser *parser);
int						link_two_nodes(t_node *one, t_node *two);
int						get_name(t_read *reader, t_link *name,
															unsigned char sep);
void					free_pathnode(t_pathnode *node);
unsigned int			print_anthill(t_data *data, unsigned int flags);

t_node					*check_room(t_parser *parser, t_link *name);
int						wrong_case(void);
void					free_everything(t_parser *parser);

#endif
