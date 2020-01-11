/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gesture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 09:55:44 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 02:33:25 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	gesture_fractal(int button, int x, int y, t_box *box)
{
	if (button == 4 && box->info.iteration > 20)
	{
		box->info.mouse.r = ((x - POS1_W) / box->info.zoom + box->info.mouse.r)
			- ((x - POS1_W - 0.12) / (box->info.zoom / 1.2));
		box->info.mouse.i = ((y - POS1_H) / box->info.zoom + box->info.mouse.i)
			- ((y - POS1_H - 0.1) / (box->info.zoom / 1.2));
		box->info.zoom /= 1.2;
		box->info.iteration -= 10;
	}
	else if (button == 5 && box->info.iteration < 4294967270)
	{
		box->info.mouse.r = ((x - POS1_W) / box->info.zoom + box->info.mouse.r)
			- ((x - POS1_W - 0.12) / (box->info.zoom * 1.2));
		box->info.mouse.i = ((y - POS1_H) / box->info.zoom + box->info.mouse.i)
			- ((y - POS1_H - 0.1) / (box->info.zoom * 1.2));
		box->info.zoom *= 1.2;
		box->info.iteration += 10;
	}
	else if (button == 1)
		box->info.lock += (box->info.lock & 1) ? -1 : 1;
	else if (button == 2)
	{
		box->info.lock += box->info.lock & 2 ? -2 : 2;
		box->info.i = 0;
	}
}

void	gesture_prev(t_box *box)
{
	if (!box->info.cur)
		box->info.cur = NB_FRACTAL - 1;
	else
		--box->info.cur;
	set_fractal(box);
	draw_render(box);
}

void	gesture_next(t_box *box)
{
	if (box->info.cur == (NB_FRACTAL - 1))
		box->info.cur = 0;
	else
		++box->info.cur;
	set_fractal(box);
	draw_render(box);
}
