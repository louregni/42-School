/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 04:06:32 by louregni          #+#    #+#             */
/*   Updated: 2019/06/23 02:49:45 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

int			julia(t_info *info, unsigned int x, unsigned int y);
int			mandelbrot(t_info *info, unsigned int x, unsigned int y);
int			burning_ship(t_info *info, unsigned int x, unsigned int y);
int			mandelbrot2(t_info *info, unsigned int x, unsigned int y);
int			tricorn(t_info *info, unsigned int x, unsigned int y);
int			mandelbrot5(t_info *info, unsigned int x, unsigned int y);
int			julia2(t_info *info, unsigned int x, unsigned int y);
int			mandelbrot4(t_info *info, unsigned int x, unsigned int y);
int			mandelbrot6(t_info *info, unsigned int x, unsigned int y);

#endif
