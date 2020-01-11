/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 04:50:36 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 02:30:00 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "render.h"

void	draw_usage(t_box *box)
{
	mlx_string_put(box->render.mlx, box->render.win, (POS3_W + 150),
			100, 0x00ff0800, "Fract'ol usage:");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 120, 0x002afc00,
			"Keyboard:");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 220, 0x0000a9b7,
			" - R : reset main fractal to default values");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 240, 0x0000a9b7,
			" - ESC : close the program");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 260, 0x002afc00,
			"Mouse:");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 320, 0x0000a9b7,
			" - On preview left-click : switch main fractal");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 300, 0x0000a9b7,
			" - Wheel : zoom / unzoom on main fractal");
	mlx_string_put(box->render.mlx, box->render.win, ((WIDTH / 2) - 42),
			100, 0x00000cff, "Main Fractal");
	mlx_string_put(box->render.mlx, box->render.win, (POS2_W + RENDER / 3),
			(POS2_H - 30), 0x0000f3ff, "Previous Fractal");
	mlx_string_put(box->render.mlx, box->render.win, (POS3_W + RENDER / 3),
			(POS2_H - 30), 0x0000f3ff, "Next Fractal");
}

void	draw_fractal_list(t_box *box)
{
	mlx_string_put(box->render.mlx, box->render.win, (POS3_W + 150), 880,
			0x00ff0800, "Fractal's list:");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 900, 0x0000a9b7,
			" - 1 : Julia               - 5 : Tricorn");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 920, 0x0000a9b7,
			" - 2 : Mandelbrot          - 6 : Mandelbrot ^5");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 940, 0x0000a9b7,
			" - 3 : Burning-Ship        - 7 : Mandelbrot ^4");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 960, 0x0000a9b7,
			" - 4 : Mandelbrot ^2       - 8 : Mandelbrot ^6");
}

void	draw_color(t_box *box)
{
	mlx_string_put(box->render.mlx, box->render.win, (POS3_W + 25), 140,
			0x0000a9b7, "Color palette:");
	mlx_string_put(box->render.mlx, box->render.win, (POS3_W + 35), 160,
			0x0000a9b7, " - Q : color A");
	mlx_string_put(box->render.mlx, box->render.win, (POS3_W + 35), 180,
			0x0000a9b7, " - W : color B");
	mlx_string_put(box->render.mlx, box->render.win, (POS3_W + 35), 200,
			0x0000a9b7, " - E : color C");
	mlx_string_put(box->render.mlx, box->render.win, POS3_W, 280, 0x0000a9b7,
			" - Right click : Enable / Disable color animation");
}

void	draw_button(t_box *box)
{
	mlx_put_image_to_window(box->render.mlx, box->render.win,
			box->render.img[1], POS2_W, POS2_H);
	mlx_put_image_to_window(box->render.mlx, box->render.win,
			box->render.img[2], POS3_W, POS2_H);
}

void	draw(t_box *box)
{
	draw_usage(box);
	draw_color(box);
	draw_fractal_list(box);
}
