/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 09:54:30 by louregni          #+#    #+#             */
/*   Updated: 2019/01/22 19:07:27 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# define WIN_WIDTH 2250
# define WIN_HEIGHT 1240

typedef struct s_img	t_img;

typedef struct			s_win
{
	t_map	*map;
	t_img	*img;
	t_point	start;
	void	*mlx_ptr;
	void	*win_ptr;
}						t_win;

struct					s_img
{
	t_point	coord;
	t_point	offset;
	t_win	*win;
	void	*img_ptr;
	char	*img_data;
	int		width;
	int		height;
	int		endian;
	int		s_l;
	int		bpp;
};

t_win					*ft_init_window(void);
t_win					*ft_clean(t_win *window);

#endif
