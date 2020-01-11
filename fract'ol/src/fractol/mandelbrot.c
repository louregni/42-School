/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 22:32:45 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 02:33:42 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"

int				mandelbrot5(t_info *info, unsigned int x, unsigned int y)
{
	long double		tmp;
	unsigned int	i;
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
		z.r = (z.r * z.r * z.r * z.r * z.r) - (10.0 * (z.r * z.r * z.r) * (z.i
					* z.i)) + (5.0 * z.r * (z.i * z.i * z.i * z.i)) + c.r;
		z.i = (5.0 * (tmp * tmp * tmp * tmp) * z.i) - (10.0 * (tmp * tmp)
				* (z.i * z.i * z.i)) + (z.i * z.i * z.i * z.i * z.i) + c.i;
		++i;
	}
	return (i);
}

int				mandelbrot6(t_info *info, unsigned int x, unsigned int y)
{
	long double		tmp;
	unsigned int	i;
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
		z.r = powl((z.r * z.r + z.i * z.i), (long double)3.0) * cosl(
				(long double)6.0 * atan2l(z.i, z.r)) + c.r;
		z.i = powl((tmp * tmp + z.i * z.i), (long double)3.0) * sinl(
				(long double)6.0 * atan2l(z.i, tmp)) + c.i;
		++i;
	}
	return (i);
}

int				mandelbrot4(t_info *info, unsigned int x, unsigned int y)
{
	long double		tmp;
	unsigned int	i;
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
		z.r = powl((z.r * z.r + z.i * z.i), (long double)2.0) * cosl(
				(long double)4.0 * atan2l(z.i, z.r)) + c.r;
		z.i = powl((tmp * tmp + z.i * z.i), (long double)2.0) * sinl(
				(long double)4.0 * atan2l(z.i, tmp)) + c.i;
		++i;
	}
	return (i);
}

int				mandelbrot2(t_info *info, unsigned int x, unsigned int y)
{
	long double		tmp;
	unsigned int	i;
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
		z.r = (z.r * z.r * z.r) - 3 * z.r * (z.i * z.i) + c.r;
		z.i = (3.0 * (tmp * tmp) * z.i) - (z.i * z.i * z.i) + c.i;
		++i;
	}
	return (i);
}
