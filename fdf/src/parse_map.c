/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:09:28 by louregni          #+#    #+#             */
/*   Updated: 2019/01/22 19:17:01 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pixel.h"
#include "get_map.h"
#include "libft.h"
#include "get_values.h"

int				ft_clear_pixeltab(char **pixel)
{
	size_t	count;

	count = 0;
	if (pixel != NULL)
	{
		while (pixel[count] != NULL)
			free(pixel[count++]);
		free(pixel);
	}
	return (0);
}

unsigned int	ft_get_ppl(char **pixel)
{
	unsigned int	ppl;

	ppl = 0;
	while (pixel[ppl] != NULL)
		++ppl;
	return (ppl);
}

int				ft_size_map(t_map *map, char *line, size_t index)
{
	char				**pixel;
	unsigned int		count;
	unsigned int		ppl;

	count = 0;
	ppl = 0;
	if (!(pixel = ft_strsplit(line, ' ')))
		return (0);
	if (map->tab[0] == NULL)
		map->width = ft_get_ppl(pixel);
	ppl = ft_get_ppl(pixel);
	if (ppl != map->width)
		return (ft_clear_pixeltab(pixel));
	if (!(map->tab[index] = malloc(sizeof(t_pixel) * ppl)))
		return (ft_clear_pixeltab(pixel));
	while (count < ppl)
	{
		if (!(ft_get_values(pixel[count], &map->tab[index][count], map)))
			return (ft_clear_pixeltab(pixel));
		count++;
	}
	ft_clear_pixeltab(pixel);
	return (1);
}

void			ft_parse_map(int fd, t_map *map)
{
	char	*line;
	size_t	count;
	int		ret;

	count = 0;
	map->tab[0] = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line != NULL && !(ft_size_map(map, line, count)))
		{
			get_next_line(fd, &line);
			ft_clear_map(map);
			free(line);
			exit(1);
		}
		free(line);
		count++;
	}
	if (ret == -1)
	{
		ft_clear_map(map);
		exit(1);
	}
}
