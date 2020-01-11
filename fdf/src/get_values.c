/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:05:58 by ckillian          #+#    #+#             */
/*   Updated: 2019/01/24 08:17:46 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pixel.h"
#include "get_map.h"
#include "libft.h"

int		ft_is_hexa(char *str, char *hexa)
{
	int	i;

	if (!(*str))
		return (0);
	while (*str)
	{
		i = 0;
		while (hexa[i] && *str != hexa[i])
			i++;
		if (hexa[i] != *str)
			return (0);
		str++;
	}
	return (1);
}

int		ft_get_values(char *str, t_pixel *pxl, t_map *map)
{
	int	height;

	if (!ft_isdigit(*str) && *str != '-' && !(ft_isdigit(*(str + 1))))
		return (0);
	height = ft_atoi(str);
	pxl->height = height;
	if (map->pmh < height)
		map->pmh = height;
	if (*str == '-')
		++str;
	while (*str && ft_isdigit(*str))
		++str;
	if (!(*str))
	{
		pxl->color = 0x6514ff;
		return (1);
	}
	if (ft_strncmp(str, ",0x", 3))
		return (0);
	str += 3;
	ft_strlowercase(str);
	if (ft_is_hexa(str, "0123456789abcdef") == 0)
		return (0);
	pxl->color = ft_atoi_base(str, "0123456789abcdef");
	return (1);
}
