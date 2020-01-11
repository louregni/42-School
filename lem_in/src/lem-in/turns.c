/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 01:31:12 by vlaroque          #+#    #+#             */
/*   Updated: 2019/12/16 15:29:20 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int		turns_count(t_data *data, t_path *path)
{
	t_path			*saved_path;
	int				turn;
	unsigned int	ants;

	turn = -1;
	ants = 0;
	while (ants < data->ants)
	{
		turn++;
		saved_path = path;
		while (saved_path)
		{
			if (turn >= saved_path->len)
			{
				if (ants < data->ants)
					saved_path->ants_to_send += 1;
				ants++;
			}
			saved_path = saved_path->next;
		}
	}
	return (turn);
}
