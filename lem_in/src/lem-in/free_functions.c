/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:54:39 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/12 02:08:26 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "algorithm.h"

int		free_steps(t_data *data)
{
	t_step *save;

	while (data->first_step)
	{
		save = data->first_step->next;
		free(data->first_step);
		data->first_step = save;
	}
	return (0);
}

int		paths_free(t_path *path)
{
	t_pathnode	*pathnode;
	t_path		*path_save;
	t_pathnode	*pathnode_save;

	while (path)
	{
		pathnode = path->pathnode;
		while (pathnode)
		{
			pathnode_save = pathnode;
			pathnode = pathnode->next;
			free(pathnode_save);
		}
		path_save = path;
		path = path->next;
		free(path_save);
	}
	return (0);
}
