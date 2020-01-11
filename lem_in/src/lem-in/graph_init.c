/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:54:51 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/11 22:07:42 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "utils.h"

int		link_two_nodes(t_node *one, t_node *two)
{
	t_edge		*tmp_edge;

	if (!(tmp_edge = ft_memalloc(sizeof(t_edge))))
		return (-1);
	tmp_edge->endpoint = two;
	tmp_edge->next = one->edge;
	one->edge = tmp_edge;
	if (!(tmp_edge = ft_memalloc(sizeof(t_edge))))
		return (-1);
	tmp_edge->endpoint = one;
	tmp_edge->next = two->edge;
	two->edge = tmp_edge;
	one->edge->opposite_edge = two->edge;
	two->edge->opposite_edge = one->edge;
	return (0);
}
