/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pixel_cord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:18:56 by louregni          #+#    #+#             */
/*   Updated: 2019/01/22 19:31:55 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "pixel.h"
#include "get_map.h"

void	ft_iso(t_pixel *pxl)
{
	double	x_temp;
	double	y_temp;

	x_temp = pxl->cord.x;
	y_temp = pxl->cord.y;
	pxl->cord.x = (cos(BETA) * pxl->cord.x + ((sin(BETA) * -1) * pxl->cord.y));
	pxl->cord.y = (sin(ALPHA) * sin(BETA)) * x_temp
					+ (cos(ALPHA) * -pxl->cord.z)
					+ ((sin(ALPHA) * cos(BETA)) * pxl->cord.y);
	pxl->cord.z = (cos(ALPHA) * sin(BETA)) * pxl->cord.x
					+ (-sin(ALPHA) * -pxl->cord.z)
					+ ((cos(ALPHA) * cos(BETA) * pxl->cord.y));
}

void	ft_para(t_pixel *pxl)
{
	pxl->cord.x = pxl->cord.x + 0.5 * cos(BETA) * -pxl->cord.z;
	pxl->cord.y = pxl->cord.y + 0.5 * sin(BETA) * -pxl->cord.z;
}

void	ft_rotation_z(t_pixel *pxl, t_view *view, int x, int y)
{
	pxl->cord.x = x * cos(view->beta) - y * sin(view->beta);
	pxl->cord.y = x * sin(view->beta) + y * cos(view->beta);
	pxl->cord.z = pxl->height * view->fact_h;
}

void	ft_rotation_y(t_pixel *pxl, t_view *view)
{
	double	temp_x;

	temp_x = pxl->cord.x;
	pxl->cord.x = pxl->cord.x * cos(view->gama) + (pxl->cord.z *
													-sin(view->gama));
	pxl->cord.z = temp_x * sin(view->gama) + pxl->cord.z *
													cos(view->gama);
}

void	ft_rotation_x(t_pixel *pxl, t_view *view)
{
	double	temp_z;

	temp_z = pxl->cord.z;
	pxl->cord.z = pxl->cord.z * cos(view->alpha)
								+ (pxl->cord.y * -sin(view->alpha));
	pxl->cord.y = temp_z * sin(view->alpha) + pxl->cord.y * cos(view->alpha);
}
