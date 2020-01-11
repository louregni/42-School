/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 05:51:01 by louregni          #+#    #+#             */
/*   Updated: 2019/12/16 05:51:01 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct s_data		t_data;
typedef struct s_edge		t_edge;
typedef struct s_node		t_node;
typedef struct s_neighbor	t_neighbor;
typedef struct s_step		t_step;
typedef struct s_fastep		t_fastep;

struct			s_step
{
	t_node		*node;
	t_neighbor	*parent_neighbor;
	t_step		*parent;
	t_step		*next;
};

struct			s_fastep
{
	t_node		node;
	int			dist;
	t_fastep	*next;
};

struct			s_neighbor
{
	t_node		*nb_node;
	t_neighbor	*oppo;
	int			flux;
	t_edge		*edge;
	t_neighbor	*next;
};

struct			s_edge
{
	t_node		*first;
	t_node		*second;
	int			flow;
	t_edge		*next;
};

struct			s_node
{
	int			id;
	int			state;
	int			fast_dist;
	t_neighbor	*neighbor;
	t_node		*next;
};

struct			s_data
{
	int			ants;
	t_node		*first_node;
	t_edge		*first_edge;
	t_node		*source;
	t_node		*sink;
	t_step		*first_step;
	t_step		*current_step;
	t_step		*last_step;
	t_fastep	*cur_fstep;
	t_fastep	*last_fstep;
};

/*
** Init Utils
*/
int				node_linker(t_data *data);
int				add_edge(t_data *data, t_node *one, t_node *two);
int				new_edge(t_data *data, int a, int b);
int				create_nodes(t_data *data, int nbr);
t_node			*pnode(t_data *data, int n);

/*
** Debug
*/

int				print_data(t_data *data);
int				printern(char *str, int ret);
int				print_path(t_data *data);

/*
** Init graph
*/

void			init_one(t_data *data);
void			init_two(t_data *data);
void			init_three(t_data *data);
void			init_four(t_data *data);
void			init_rand(t_data *data);

#endif
