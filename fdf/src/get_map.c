/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:57:53 by louregni          #+#    #+#             */
/*   Updated: 2019/01/22 19:14:01 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "pixel.h"
#include "get_map.h"
#include "libft.h"
#include "init_map.h"
#include "parse_map.h"

void	ft_clear_map(t_map *map)
{
	size_t	count;

	if (map == NULL)
		return ;
	count = 0;
	if (map->tab != NULL)
	{
		while (map->tab[count] != NULL && count < map->height)
		{
			free(map->tab[count]);
			++count;
		}
		free(map->tab);
	}
	free(map);
}

t_map	*ft_get_map(char *file)
{
	int			fd;
	t_map		*map;

	if ((fd = open(file, O_RDONLY)) == -1)
		exit(1);
	if (!(map = malloc(sizeof(t_map))))
	{
		close(fd);
		exit(1);
	}
	ft_memset(map, 0, sizeof(t_map));
	ft_create_map(fd, map);
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_clear_map(map);
		exit(1);
	}
	ft_parse_map(fd, map);
	ft_init_view(map);
	return (map);
}
