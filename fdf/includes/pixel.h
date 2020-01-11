/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:24:58 by louregni          #+#    #+#             */
/*   Updated: 2019/01/22 16:58:36 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct	s_pixel
{
	double				height;
	unsigned int		color;
	t_point				cord;
}				t_pixel;

#endif
