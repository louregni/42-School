/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:23:46 by ckillian          #+#    #+#             */
/*   Updated: 2019/01/23 17:36:46 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pixel.h"
#include "get_map.h"
#include "window.h"
#include "mlx.h"
#include "draw.h"
#include "key.h"

int	ft_close(t_win *window)
{
	ft_clear_map(window->map);
	ft_clean(window);
	exit(1);
}

int	main(int ac, char *av[])
{
	t_map	*map;
	t_win	*window;

	window = NULL;
	if (ac != 2)
		return (0);
	if (!(map = ft_get_map(av[1])))
		return (0);
	if (!(window = ft_init_window()))
	{
		ft_clear_map(map);
		return (0);
	}
	window->map = map;
	ft_pixel_cord(window->map);
	ft_draw(window);
	ft_print_usage(window);
	mlx_hook(window->win_ptr, 2, (1L << 0), &deal_key, window);
	mlx_hook(window->win_ptr, 17, (1L << 17), &ft_close, window);
	mlx_loop(window->mlx_ptr);
	return (0);
}
