/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:47:39 by ckillian          #+#    #+#             */
/*   Updated: 2019/01/22 19:22:23 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pixel.h"
#include "get_map.h"
#include "window.h"
#include "libft.h"
#include "mlx.h"

t_win	*ft_clean(t_win *window)
{
	if (window->img)
	{
		mlx_destroy_image(window->mlx_ptr, window->img->img_ptr);
		free(window->img);
	}
	if (window->win_ptr)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	return (NULL);
}

int		ft_init_img(t_win *window)
{
	t_img	*image;

	if (!(window->img = malloc(sizeof(t_img))))
		return (-1);
	ft_bzero(window->img, sizeof(t_img));
	image = window->img;
	image->win = window;
	image->coord.x = 0;
	image->coord.y = 0;
	image->img_ptr = mlx_new_image(image->win->mlx_ptr,
					MAP_WIDTH, MAP_HEIGHT);
	image->img_data = mlx_get_data_addr(image->img_ptr,
			&(image->bpp), &(image->s_l), &(image->endian));
	return (1);
}

t_win	*ft_init_window(void)
{
	t_win	*window;

	if (!(window = malloc(sizeof(t_win))))
		return (NULL);
	ft_bzero(window, sizeof(t_win));
	if (!(window->mlx_ptr = mlx_init()))
		return (ft_clean(window));
	if (!(window->win_ptr = mlx_new_window(window->mlx_ptr,
											WIN_WIDTH, WIN_HEIGHT, "FDF")))
		return (ft_clean(window));
	if (ft_init_img(window) == -1)
		return (ft_clean(window));
	return (window);
}
