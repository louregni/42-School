/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 02:38:17 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 01:22:13 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "render.h"
#include "fractal.h"

void	set_fractal(t_box *box)
{
	box->info.cord.r = box->render.cord[0][0].r;
	box->info.cord.i = box->render.cord[0][0].i;
	box->info.mouse.r = box->render.fractal[0][box->info.cur].r;
	box->info.mouse.i = box->render.fractal[0][box->info.cur].i;
	box->info.zoom = box->render.zoom[0][box->info.cur];
	box->info.iteration = box->render.iteration[0][box->info.cur];
}

void	set_fractal_preview(t_box *box, unsigned int i)
{
	box->render.info.cord.r = box->render.cord[1][0].r;
	box->render.info.cord.i = box->render.cord[1][0].i;
	box->render.info.mouse.r = box->render.fractal[1][i].r;
	box->render.info.mouse.i = box->render.fractal[1][i].i;
	box->render.info.lock = 0;
	box->render.info.zoom = box->render.zoom[1][i];
	box->render.info.iteration = box->render.iteration[1][i];
}

void	bind_fractal(t_info *info)
{
	info->fractal[0] = &julia;
	info->fractal[1] = &mandelbrot;
	info->fractal[2] = &burning_ship;
	info->fractal[3] = &mandelbrot2;
	info->fractal[4] = &tricorn;
	info->fractal[5] = &mandelbrot5;
	info->fractal[6] = &mandelbrot4;
	info->fractal[7] = &mandelbrot6;
}

void	init_thread(t_box *box)
{
	unsigned int i;

	i = 0;
	box->info.increment = 1;
	box->info.c = 0;
	box->info.i = 0;
	while (i < NB_THREAD)
	{
		box->settings[i].info = &box->info;
		box->settings[i].id = i;
		++i;
	}
}

int		initialize(t_box *box)
{
	int	bpp;
	int	sizeline;
	int	endian;

	if (!(box->render.mlx = mlx_init()))
		return (1);
	if (!(box->render.win = mlx_new_window(box->render.mlx,
					WIDTH, HEIGHT, "Fractol")))
		return (1);
	if (!(box->render.img[0] = mlx_new_image(box->render.mlx, IMG_W, IMG_H)))
		return (1);
	if (!(box->render.img[1] = mlx_new_image(box->render.mlx, RENDER, RENDER)))
		return (1);
	if (!(box->render.img[2] = mlx_new_image(box->render.mlx, RENDER, RENDER)))
		return (1);
	box->info.buffer = (unsigned int *)mlx_get_data_addr(box->render.img[0],
			&bpp, &sizeline, &endian);
	box->render.buffer[0] = (unsigned int *)
		mlx_get_data_addr(box->render.img[1], &bpp, &sizeline, &endian);
	box->render.buffer[1] = (unsigned int *)
		mlx_get_data_addr(box->render.img[2], &bpp, &sizeline, &endian);
	if (!box->info.buffer || !box->render.buffer[0] || !box->render.buffer[1])
		return (1);
	bind_fractal(&box->info);
	return (0);
}
