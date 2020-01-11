/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:55:47 by louregni          #+#    #+#             */
/*   Updated: 2019/01/22 19:06:33 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIMENSION_H
# define DIMENSION_H

void	ft_rotation_z(t_pixel *pxl, t_view *view, int x, int y);
void	ft_rotation_y(t_pixel *pxl, t_view *view);
void	ft_rotation_x(t_pixel *pxl, t_view *view);
void	ft_para(t_pixel *pxl);
void	ft_iso(t_pixel *pxl);

#endif
