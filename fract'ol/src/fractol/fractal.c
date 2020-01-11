/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 04:00:46 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 02:31:31 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"

int				julia(t_info *info, unsigned int x, unsigned int y)
{
	unsigned int	i;
	long double		tmp;
	t_complex		c;
	t_complex		z;

	c.r = info->cord.r;
	c.i = info->cord.i;
	z.r = ((long double)x / info->zoom) + info->mouse.r;
	z.i = ((long double)y / info->zoom) + info->mouse.i;
	i = 0;
	while (((z.r * z.r) + (z.i * z.i) < 4.0 && i < info->iteration))
	{
		tmp = z.r;
		z.r = ((z.r * z.r) - (z.i * z.i)) + c.r;
		z.i = 2.0 * z.i * tmp + c.i;
		++i;
	}
	return (i);
}

int				burning_ship(t_info *info, unsigned int x, unsigned int y)
{
	unsigned int	i;
	long double		tmp;
	t_complex		c;
	t_complex		z;

	c.r = (long double)x / info->zoom + info->mouse.r;
	c.i = (long double)y / info->zoom + info->mouse.i;
	z.r = 0;
	z.i = 0;
	i = 0;
	while (((z.r * z.r) + (z.i * z.i)) < 4.0 && i < info->iteration)
	{
		tmp = z.r;
		z.r = fabsl(((z.r * z.r) - (z.i * z.i)) + c.r);
		z.i = fabsl(2.0 * z.i * tmp) + c.i;
		++i;
	}
	return (i);
}

int				tricorn(t_info *info, unsigned int x, unsigned int y)
{
	unsigned int	i;
	long double		tmp;
	t_complex		c;
	t_complex		z;

	c.r = (long double)x / info->zoom + info->mouse.r;
	c.i = (long double)y / info->zoom + info->mouse.i;
	z.r = c.r;
	z.i = c.i;
	i = 0;
	while (((z.r * z.r) + (z.i * z.i)) < 4.0 && i < info->iteration)
	{
		tmp = ((z.r * z.r) - (z.i * z.i)) + c.r;
		z.i = -2 * z.i * z.r + c.i;
		z.r = tmp;
		++i;
	}
	return (i);
}

int				mandelbrot(t_info *info, unsigned int x, unsigned int y)
{
	unsigned int	i;
	long double		tmp;
	t_complex		c;
	t_complex		z;

	c.r = (long double)x / info->zoom + info->mouse.r;
	c.i = (long double)y / info->zoom + info->mouse.i;
	z.r = 0.;
	z.i = 0.;
	i = 0;
	while (((z.r * z.r) + (z.i * z.i)) < 4.0 && i < info->iteration)
	{
		tmp = z.r;
		z.r = ((z.r * z.r) - (z.i * z.i)) + c.r;
		z.i = 2.0 * z.i * tmp + c.i;
		++i;
	}
	return (i);
}

void			draw_fractal(t_info *info, unsigned int *buffer,
		int (*fractal)(t_info *info, unsigned int x, unsigned int y))
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	x = 0;
	while (x < RENDER)
	{
		y = 0;
		while (y < RENDER)
		{
			i = fractal(info, x, y);
			if (i == info->iteration)
				buffer[y * RENDER + x] = 0x00000000;
			else
				buffer[y * RENDER + x] = set_color_preview(i);
			++y;
		}
		++x;
	}
}
