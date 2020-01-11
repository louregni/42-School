/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:52:06 by louregni          #+#    #+#             */
/*   Updated: 2019/01/22 19:15:42 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "pixel.h"
#include "get_map.h"
#include "libft.h"

void		ft_init_view(t_map *map)
{
	map->view.type = ISO;
	map->view.zoom = ((MAP_WIDTH / map->width)
			+ (MAP_HEIGHT / map->height)) * 0.5;
	map->view.alpha = 0;
	map->view.beta = 0;
	map->view.gama = 0;
	map->view.offsetx = MAP_WIDTH / 2;
	map->view.offsety = MAP_HEIGHT / 2;
	map->view.fact_h = 1;
}

void		ft_create_map(int fd, t_map *map)
{
	char			*line;
	int				ret;
	unsigned int	line_nbr;

	line_nbr = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		free(line);
		++line_nbr;
	}
	map->height = line_nbr;
	if ((ret == -1) || !(map->tab = malloc(line_nbr * sizeof(t_pixel *))))
	{
		close(fd);
		ft_clear_map(map);
		exit(1);
	}
	ft_memset(map->tab, 0, line_nbr * sizeof(t_pixel *));
	if (close(fd) == -1)
	{
		ft_clear_map(map);
		exit(1);
	}
}
