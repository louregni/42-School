/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:06:04 by louregni          #+#    #+#             */
/*   Updated: 2018/12/03 15:29:27 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	ft_check_line_f2(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 3 * 5) > 19)
		return (0);
	i += 5;
	while (j < 3)
	{
		if (tetr[i + (j * 5)] != '#')
			return (0);
		j++;
	}
	return (FACE_2);
}

unsigned short	ft_check_line_f1(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 3) > 19)
		return (0);
	i++;
	while (j < 3)
		if (tetr[i + j++] != '#')
			return (0);
	return (FACE_1);
}

short			ft_check_line(char *tetr)
{
	int				i;
	unsigned short	result;

	i = 0;
	result = LINE;
	while (tetr[i] && tetr[i] != '#')
		i++;
	if (!tetr[i])
		return (0);
	if ((result |= ft_check_line_f1(tetr, i)) != LINE)
		return (result);
	if ((result |= ft_check_line_f2(tetr, i)) != LINE)
		return (result);
	return (0);
}
