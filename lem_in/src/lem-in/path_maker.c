/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 01:30:11 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/12 01:32:00 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void		edge_flux(t_edge *edge, int flux)
{
	edge->flux = flux;
	edge->opposite_edge->flux = -flux;
}

int			trace_path(t_data *data, t_step *step, t_edge *edge)
{
	edge_flux(edge, 1);
	while (step->node != data->source)
	{
		step->node->crossed = 1;
		if (step->prev_edge->flux == 0)
			edge_flux(step->prev_edge, 1);
		else if (step->prev_edge->flux == -1)
			edge_flux(step->prev_edge, 0);
		step = step->prev_step;
	}
	return (1);
}
