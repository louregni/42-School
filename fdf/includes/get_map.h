/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:25:20 by louregni          #+#    #+#             */
/*   Updated: 2019/01/22 19:06:45 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H
# define ISO 1
# define PARA 2
# define MAP_WIDTH	1800
# define MAP_HEIGHT	1240
# define ALPHA 0.611
# define BETA 0.785

typedef struct		s_view
{
	int					type;
	double				zoom;
	double				alpha;
	double				beta;
	double				gama;
	double				offsetx;
	double				offsety;
	double				fact_h;
}					t_view;

typedef struct		s_map
{
	unsigned short int	height;
	unsigned short int	width;
	double				pmh;
	t_pixel				**tab;
	t_view				view;
}					t_map;

void				ft_clear_map(t_map	*map);
t_map				*ft_get_map(char *file);

#endif
