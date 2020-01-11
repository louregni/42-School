/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:08:03 by ckillian          #+#    #+#             */
/*   Updated: 2019/01/22 19:24:03 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"
#include "get_map.h"
#include "window.h"
#include "mlx.h"
#include "plot.h"
#include "dimension.h"

void	ft_print_usage2(t_win *window)
{
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 750, 0x0077FF, "Rotation Y : ARROW RIGHT / LEFT");
	mlx_string_put(window->mlx_ptr,
		window->win_ptr, 1870, 800, 0x0077FF, "Rotation X : ARROW UP / DOWN");
	mlx_string_put(window->mlx_ptr,
		window->win_ptr, 1870, 850, 0x0077FF, "Rotation Z : PAGE UP / DOWN");
}

void	ft_print_usage(t_win *window)
{
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1820, 150, 0xFF0022, "Usage :");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 200, 0x0077FF, "Move map to the right : L");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 250, 0x0077FF, "Move map to the left : H");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 300, 0x0077FF, "Move map up : K");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 350, 0x0077FF, "Move map down : J");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 400, 0x0077FF, "Zoom increase : +");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 450, 0x0077FF, "Zoom decrease : -");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 500, 0x0077FF, "Increase map heights : M");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 550, 0x0077FF, "Decrease map heights : N");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 600, 0x0077FF, "Parallel view : P");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 650, 0x0077FF, "Isometric view : I");
	mlx_string_put(window->mlx_ptr, window->win_ptr,
			1870, 700, 0x0077FF, "Reset settings : R");
	ft_print_usage2(window);
}

void	ft_draw_lines(int x, int y, t_win *window)
{
	if (x + 1 < window->map->width)
		ft_plot_line(window->map->tab[y][x].cord,
	window->map->tab[y][x + 1].cord, window, window->map->tab[y][x].color);
	if (y + 1 < window->map->height)
		ft_plot_line(window->map->tab[y][x].cord,
	window->map->tab[y + 1][x].cord, window, window->map->tab[y][x].color);
}

void	ft_pixel_cord(t_map *map)
{
	int		x;
	int		y;
	void	(*matrix)(t_pixel *pixel);

	if (map->view.type == 1)
		matrix = &ft_iso;
	else
		matrix = &ft_para;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			ft_rotation_z(&(map->tab[y][x]), &map->view,
							x - map->width / 2, y - map->height / 2);
			ft_rotation_x(&(map->tab[y][x]), &map->view);
			ft_rotation_y(&(map->tab[y][x]), &map->view);
			matrix(&(map->tab[y][x]));
		}
	}
}

void	ft_draw(t_win *window)
{
	int		x;
	int		y;
	t_img	*img;

	img = window->img;
	y = -1;
	while (++y < window->map->height)
	{
		x = -1;
		while (++x < window->map->width)
		{
			ft_draw_lines(x, y, window);
		}
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr,
			img->img_ptr, img->coord.x, img->coord.y);
}
