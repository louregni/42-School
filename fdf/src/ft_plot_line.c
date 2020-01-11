/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plot_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:15:32 by ckillian          #+#    #+#             */
/*   Updated: 2019/01/22 19:21:34 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "pixel.h"
#include "get_map.h"
#include "window.h"
#include "mlx.h"

void	ft_plot(int x, int y, unsigned int color, t_img *img)
{
	if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT)
		return ;
	*(unsigned int *)(&img->img_data[y * (MAP_WIDTH * 4) + (x * 4)]) |=
		mlx_get_color_value(img->win->mlx_ptr, color);
}

void	ft_plot_line_low(t_point a, t_point b, t_img *toto, unsigned int color)
{
	t_point	dif;
	int		y;
	int		x;
	int		d;
	int		neg;

	dif.x = b.x - a.x;
	dif.y = b.y - a.y;
	neg = 1;
	if (dif.y < 0)
	{
		neg = -1;
		dif.y *= -1;
	}
	d = 2 * dif.y - dif.x;
	y = a.y;
	x = a.x - 1;
	while (++x <= b.x)
	{
		ft_plot(x, y, color, toto);
		if (d > 0 && (y += neg) != 0.5)
			d -= 2 * dif.x;
		d += 2 * dif.y;
	}
}

void	ft_plot_line_high(t_point a, t_point b, t_img *toto, int color)
{
	t_point	dif;
	int		y;
	int		x;
	int		d;
	int		neg;

	dif.x = b.x - a.x;
	dif.y = b.y - a.y;
	neg = 1;
	if (dif.x < 0)
	{
		neg = -1;
		dif.x *= -1;
	}
	d = 2 * dif.x - dif.y;
	y = a.y - 1;
	x = a.x;
	while (++y <= b.y)
	{
		ft_plot(x, y, color, toto);
		if (d > 0 && (x += neg) != 0.2)
			d -= 2 * dif.y;
		d += 2 * dif.x;
	}
}

void	ft_plot_line(t_point a, t_point b, t_win *window, int color)
{
	a.x = (a.x * window->map->view.zoom) + window->map->view.offsetx;
	a.y = (a.y * window->map->view.zoom) + window->map->view.offsety;
	b.x = (b.x * window->map->view.zoom) + window->map->view.offsetx;
	b.y = (b.y * window->map->view.zoom) + window->map->view.offsety;
	if (fabs(b.y - a.y) < fabs(b.x - a.x))
	{
		if (a.x > b.x)
			ft_plot_line_low(b, a, window->img, color);
		else
			ft_plot_line_low(a, b, window->img, color);
	}
	else
	{
		if (a.y > b.y)
			ft_plot_line_high(b, a, window->img, color);
		else
			ft_plot_line_high(a, b, window->img, color);
	}
}
