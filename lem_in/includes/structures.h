/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 04:38:11 by louregni          #+#    #+#             */
/*   Updated: 2019/12/16 04:38:12 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_cord
{
	unsigned int		x;
	unsigned int		y;
}					t_cord;

typedef struct		s_id
{
	unsigned int		size;
	unsigned char		name[12];
	unsigned char		*ptr;
}					t_id;

typedef struct		s_name
{
	unsigned char		*name;
	unsigned int		size;
}					t_name;

typedef struct		s_node
{
	struct s_name		name;
	struct s_cord		cord;
	struct s_edge		*edge;
	struct s_node		*next;
	int					crossed;
	int					dist;
	int					id;
}					t_node;

typedef struct		s_edge
{
	int					flux;
	struct s_node		*endpoint;
	struct s_edge		*opposite_edge;
	struct s_edge		*next;
}					t_edge;

typedef struct		s_step
{
	struct s_node		*node;
	struct s_step		*prev_step;
	struct s_edge		*prev_edge;
	int					mode;
	int					dist;
	struct s_step		*next;
}					t_step;

typedef struct		s_path
{
	struct s_pathnode	*pathnode;
	struct s_path		*next;
	int					len;
	unsigned int		ants_to_send;
}					t_path;

typedef struct		s_pathnode
{
	struct s_node		*node;
	struct s_pathnode	*next;
	struct s_pathnode	*prev;
	t_id				id;
}					t_pathnode;

typedef struct		s_data
{
	struct s_node		*first_node;
	struct s_node		*source;
	struct s_node		*sink;
	struct s_step		*first_step;
	struct s_step		*current_step;
	struct s_step		*last_step;
	struct s_path		*cur_path;
	struct s_path		*saved_path;
	unsigned int		ants;
	int					cur_path_turns;
	int					saved_path_turns;
}					t_data;

#endif
