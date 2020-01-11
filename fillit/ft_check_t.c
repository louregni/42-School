/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:14:58 by louregni          #+#    #+#             */
/*   Updated: 2018/12/06 14:24:30 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	ft_check_t_f1(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 1 * 5 + 1) > 19)
		return (0);
	while (j < 3)
	{
		if (tetr[i + j] != '#')
			return (0);
		if (j == 1 && tetr[i + j + 5] != '#')
			return (0);
		j++;
	}
	return (FACE_1);
}

unsigned short	ft_check_t_f4(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 2 * 5) > 19)
		return (0);
	while (j < 3)
	{
		if (tetr[i + (j * 5)] != '#')
			return (0);
		if (j == 1 && tetr[i + (j * 5) - 1] != '#')
			return (0);
		j++;
	}
	return (FACE_4);
}

unsigned short	ft_check_t_f3(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 1 * 5 + 1) > 19)
		return (0);
	while (j < 3)
	{
		if (tetr[(i + 5 - 1) + j] != '#')
			return (0);
		j++;
	}
	return (FACE_3);
}

unsigned short	ft_check_t_f2(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 2 * 5) > 19)
		return (0);
	while (j < 3)
	{
		if (tetr[i + (j * 5)] != '#')
			return (0);
		if (j == 1 && tetr[i + (j * 5) + 1] != '#')
			return (0);
		j++;
	}
	return (FACE_2);
}

short			ft_check_t(char *tetr)
{
	int				i;
	unsigned short	result;

	i = 0;
	result = TEA;
	while (tetr[i] && tetr[i] != '#')
		i++;
	if (!tetr[i])
		return (0);
	if ((result |= ft_check_t_f1(tetr, i)) != TEA)
		return ((short)result);
	if ((result |= ft_check_t_f2(tetr, i)) != TEA)
		return ((short)result);
	if ((result |= ft_check_t_f3(tetr, i)) != TEA)
		return ((short)result);
	if ((result |= ft_check_t_f4(tetr, i)) != TEA)
		return ((short)result);
	return (0);
}
