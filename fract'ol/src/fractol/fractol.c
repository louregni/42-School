/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 04:02:42 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 02:45:08 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include "render.h"

void	init_fractal(t_render *render)
{
	init_real(render);
	init_imagin(render);
	init_zoom(render);
	init_iteration(render);
	init_cord(render);
}

int		close_render(t_render *render)
{
	if (render->mlx)
	{
		if (render->win)
		{
			if (render->img[0])
			{
				mlx_destroy_image(render->mlx, render->img[0]);
				if (render->img[1])
				{
					mlx_destroy_image(render->mlx, render->img[1]);
					if (render->img[2])
						mlx_destroy_image(render->mlx, render->img[2]);
				}
			}
			mlx_destroy_window(render->mlx, render->win);
		}
		free(render->mlx);
	}
	exit(0);
	return (1);
}

int		check_fractal(t_box *box, char *str)
{
	if (str[0] > '0' && str[0] < '9' && !str[1])
		box->info.cur = str[0] - '1';
	else
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_box		box;

	if (ac != 2 || !check_fractal(&box, av[1]))
	{
		write(2, "usage: ./fractol <id number fractal>\n", 37);
		write(2, " - 1 : Julia               - 5 : Tricorn\n", 41);
		write(2, " - 2 : Mandelbrot          - 6 : Mandelbrot ^5\n", 47);
		write(2, " - 3 : Burning-Ship        - 7 : Mandelbrot ^4\n", 47);
		write(2, " - 4 : Mandelbrot ^2       - 8 : Mandelbrot ^6\n", 47);
		return (0);
	}
	if (initialize(&box))
	{
		write(2, "Minilib'x initialisation failed !\n", 34);
		return (close_render(&box.render));
	}
	box.info.lock = 0;
	init_fractal(&box.render);
	set_fractal(&box);
	init_thread(&box);
	init_color(box.info.color);
	rendering(&box);
	return (0);
}
