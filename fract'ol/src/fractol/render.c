/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 04:02:15 by louregni          #+#    #+#             */
/*   Updated: 2019/06/19 07:01:50 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "render.h"

int			rendering(t_box *box)
{
	draw_render(box);
	draw(box);
	mlx_hook(box->render.win, 6, 0, &mouse_pos, box);
	mlx_hook(box->render.win, 4, 0, &mouse, box);
	mlx_hook(box->render.win, 2, 0, &key, box);
	mlx_hook(box->render.win, 17, 0, &close_render, &box->render);
	mlx_loop_hook(box->render.mlx, &thread_caller, box);
	mlx_loop(box->render.mlx);
	return (1);
}
