/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 04:50:42 by louregni          #+#    #+#             */
/*   Updated: 2019/12/18 04:50:48 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "structures.h"

t_path		*algorithm(t_data *data);

/*
** Graph_init
*/

int			node_init(t_data *data, int nbr);

/*
** Paths_maker
*/

int			trace_path(t_data *data, t_step *step, t_edge *edge);

/*
** Paths_manger
*/

int			paths_saver(t_data *data);

/*
** Turns
*/

int			turns_count(t_data *data, t_path *path);

/*
** free_functions
*/

int			free_steps(t_data *data);
int			paths_free(t_path *path);

#endif
