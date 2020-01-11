/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 07:06:04 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 02:34:22 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_cord(t_render *render)
{
	render->cord[0][0].r = -0.4;
	render->cord[0][0].i = 0.6;
	render->cord[1][0].r = -0.4;
	render->cord[1][0].i = 0.6;
}

void	init_iteration(t_render *render)
{
	render->iteration[0][0] = 150;
	render->iteration[0][1] = 50;
	render->iteration[0][2] = 50;
	render->iteration[0][3] = 50;
	render->iteration[0][4] = 50;
	render->iteration[0][5] = 50;
	render->iteration[0][6] = 25;
	render->iteration[0][7] = 25;
	render->iteration[1][0] = 75;
	render->iteration[1][1] = 50;
	render->iteration[1][2] = 50;
	render->iteration[1][3] = 50;
	render->iteration[1][4] = 50;
	render->iteration[1][5] = 50;
	render->iteration[1][6] = 10;
	render->iteration[1][7] = 10;
}

void	init_zoom(t_render *render)
{
	render->zoom[0][0] = 420.0;
	render->zoom[0][1] = 300.0;
	render->zoom[0][2] = 300.0;
	render->zoom[0][3] = 300.0;
	render->zoom[0][4] = 242.0;
	render->zoom[0][5] = 300.0;
	render->zoom[0][6] = 300.0;
	render->zoom[0][7] = 300.0;
	render->zoom[1][0] = 190.0;
	render->zoom[1][1] = 200.0;
	render->zoom[1][2] = 170.0;
	render->zoom[1][3] = 170.0;
	render->zoom[1][4] = 142.0;
	render->zoom[1][5] = 200.0;
	render->zoom[1][6] = 200.0;
	render->zoom[1][7] = 200.0;
}

void	init_real(t_render *render)
{
	render->fractal[0][0].r = -1.2;
	render->fractal[0][1].r = -2.3;
	render->fractal[0][2].r = -2.1;
	render->fractal[0][3].r = -1.73;
	render->fractal[0][4].r = -2.21;
	render->fractal[0][5].r = -1.7;
	render->fractal[0][6].r = -1.7;
	render->fractal[0][7].r = -1.7;
	render->fractal[1][0].r = -1.4;
	render->fractal[1][1].r = -1.9;
	render->fractal[1][2].r = -1.8;
	render->fractal[1][3].r = -1.5;
	render->fractal[1][4].r = -1.9;
	render->fractal[1][5].r = -1.4;
	render->fractal[1][6].r = -1.4;
	render->fractal[1][7].r = -1.4;
}

void	init_imagin(t_render *render)
{
	render->fractal[0][0].i = -1.2;
	render->fractal[0][1].i = -1.6;
	render->fractal[0][2].i = -2.1;
	render->fractal[0][3].i = -1.73;
	render->fractal[0][4].i = -2.0;
	render->fractal[0][5].i = -1.6;
	render->fractal[0][6].i = -1.6;
	render->fractal[0][7].i = -1.6;
	render->fractal[1][0].i = -1.4;
	render->fractal[1][1].i = -1.2;
	render->fractal[1][2].i = -1.8;
	render->fractal[1][3].i = -1.5;
	render->fractal[1][4].i = -1.72;
	render->fractal[1][5].i = -1.2;
	render->fractal[1][6].i = -1.2;
	render->fractal[1][7].i = -1.2;
}
