/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 04:51:02 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 02:49:22 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "render.h"

int		mouse_pos(int x, int y, t_box *box)
{
	if (x > POS1_W && x < (POS1_W + IMG_W)
			&& y > POS1_H && y < (POS1_H + IMG_H))
	{
		if (!(box->info.lock & 1))
		{
			box->info.cord.r = (x - POS1_W) / 1000.;
			box->info.cord.i = (y - POS1_H) / 1000.;
		}
	}
	return (0);
}

int		mouse(int button, int x, int y, t_box *box)
{
	if (x > POS1_W && x < (POS1_W + IMG_W) && y > POS1_H
			&& y < (POS1_H + IMG_H))
		gesture_fractal(button, x, y, box);
	else if (button == 1 && x > POS2_W && x < (POS2_W + RENDER)
			&& y > POS2_H && y < (POS2_H + RENDER))
		gesture_prev(box);
	else if (button == 1 && x > POS3_W && x < (POS3_W + RENDER)
			&& y > POS2_H && y < (POS2_H + RENDER))
		gesture_next(box);
	return (0);
}

void	fractal(int key, t_box *box)
{
	if (key == 18)
		box->info.cur = 0;
	else if (key == 19)
		box->info.cur = 1;
	else if (key == 20)
		box->info.cur = 2;
	else if (key == 21)
		box->info.cur = 3;
	else if (key == 23)
		box->info.cur = 4;
	else if (key == 22)
		box->info.cur = 5;
	else if (key == 26)
		box->info.cur = 6;
	else if (key == 28)
		box->info.cur = 7;
	set_fractal(box);
	draw_render(box);
}

int		key(int key, t_box *box)
{
	if (key == 123)
		box->info.mouse.r += 0.1;
	else if (key == 124)
		box->info.mouse.r -= 0.1;
	else if (key == 125)
		box->info.mouse.i -= 0.1;
	else if (key == 126)
		box->info.mouse.i += 0.1;
	else if (key == 15)
		set_fractal(box);
	else if (key > 17 && key < 29)
		fractal(key, box);
	else if (key == 53)
		close_render(&box->render);
	else if (key > 11 && key < 15)
		box->info.c = key - 12;
	return (0);
}

void	draw_render(t_box *box)
{
	if (!box->info.cur)
	{
		set_fractal_preview(box, (NB_FRACTAL - 1));
		draw_fractal(&box->render.info, box->render.buffer[0],
				box->info.fractal[NB_FRACTAL - 1]);
	}
	else
	{
		set_fractal_preview(box, (box->info.cur - 1));
		draw_fractal(&box->render.info, box->render.buffer[0],
				box->info.fractal[box->info.cur - 1]);
	}
	if (box->info.cur == (NB_FRACTAL - 1))
	{
		set_fractal_preview(box, 0);
		draw_fractal(&box->render.info, box->render.buffer[1],
				box->info.fractal[0]);
	}
	else
	{
		set_fractal_preview(box, box->info.cur + 1);
		draw_fractal(&box->render.info, box->render.buffer[1],
				box->info.fractal[box->info.cur + 1]);
	}
	draw_button(box);
}
