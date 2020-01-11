/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:39:57 by louregni          #+#    #+#             */
/*   Updated: 2019/01/22 20:01:29 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "pixel.h"
#include "get_map.h"
#include "window.h"
#include "mlx.h"
#include "draw.h"
#include "init_map.h"

void	refresh_window(t_win *window)
{
	t_img	*img;

	img = window->img;
	mlx_destroy_image(window->mlx_ptr, img->img_ptr);
	img->img_ptr = mlx_new_image(window->mlx_ptr, MAP_WIDTH, MAP_HEIGHT);
	img->img_data = mlx_get_data_addr(img->img_ptr,
					&img->bpp, &img->s_l, &img->endian);
	ft_draw(window);
}

void	move(int key, t_win *window)
{
	if (key == 4)
		window->map->view.offsetx -= 0.01 * window->map->view.zoom *
									(MAP_WIDTH / window->map->view.zoom);
	else if (key == 37)
		window->map->view.offsetx += 0.01 * window->map->view.zoom *
									(MAP_WIDTH / window->map->view.zoom);
	else if (key == 38)
		window->map->view.offsety += 0.01 * window->map->view.zoom *
									(MAP_WIDTH / window->map->view.zoom);
	else if (key == 40)
		window->map->view.offsety -= 0.01 * window->map->view.zoom *
									(MAP_WIDTH / window->map->view.zoom);
	else if (key == 24)
		window->map->view.zoom *= 1.10;
	else if (key == 27)
		window->map->view.zoom *= 0.91;
}

void	view(int key, t_win *window)
{
	if (key == 15 || key == 34 || key == 35 || key == 116
		|| key == 121 || (key >= 123 && key <= 126))
	{
		if (key == 15)
			ft_init_view(window->map);
		else if (key == 35)
			window->map->view.type = PARA;
		else if (key == 34)
			window->map->view.type = ISO;
		if (key == 123)
			window->map->view.beta -= M_PI / 60;
		else if (key == 124)
			window->map->view.beta += M_PI / 60;
		else if (key == 125)
			window->map->view.alpha += M_PI / 60;
		else if (key == 126)
			window->map->view.alpha -= M_PI / 60;
		else if (key == 116)
			window->map->view.gama -= M_PI / 60;
		else if (key == 121)
			window->map->view.gama += M_PI / 60;
		ft_pixel_cord(window->map);
	}
}

void	manage_height(int key, t_map *map)
{
	if (key == 45)
		map->view.fact_h *= 0.91;
	if (key == 46)
		map->view.fact_h *= 1.10;
	ft_pixel_cord(map);
}

int		deal_key(int key, t_win *window)
{
	move(key, window);
	view(key, window);
	manage_height(key, window->map);
	if (key == 53)
	{
		ft_clear_map(window->map);
		ft_clean(window);
		exit(0);
	}
	refresh_window(window);
	return (0);
}
