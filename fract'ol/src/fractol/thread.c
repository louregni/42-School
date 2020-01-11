/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 02:42:32 by louregni          #+#    #+#             */
/*   Updated: 2019/06/20 01:02:40 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "render.h"

void	executer(t_view *view)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	limit;
	unsigned int	save;
	unsigned int	i;

	x = 0 + view->info->increment;
	limit = (view->id * LIMIT) + LIMIT;
	save = limit - LIMIT;
	while (x < IMG_W)
	{
		y = save;
		while (y < limit)
		{
			i = (view->info->fractal[view->info->cur])(view->info, x, y);
			if (i == view->info->iteration)
				view->info->buffer[y * IMG_W + x] = 0x00000000;
			else
				view->info->buffer[y * IMG_W + x] = view->info->color
					[view->info->c][((i + view->info->i) > 7) ?
					((i + view->info->i) % 8) : (i + view->info->i)];
			++y;
		}
		x += 8;
	}
}

int		thread_caller(t_box *box)
{
	unsigned int	i;
	void			*ret;

	i = 0;
	if (box->info.increment == 8)
	{
		if (box->info.lock & 2)
			box->info.i = box->info.i == 8 ? 1 : box->info.i + 1;
		box->info.increment = 0;
	}
	else
		++box->info.increment;
	while (i < NB_THREAD)
	{
		pthread_create(&box->render.thread[i], 0, (void *)&executer,
				&box->settings[i]);
		++i;
	}
	--i;
	while (i)
		pthread_join(box->render.thread[i--], &ret);
	mlx_put_image_to_window(box->render.mlx, box->render.win,
			box->render.img[0], POS1_W, POS1_H);
	return (1);
}
