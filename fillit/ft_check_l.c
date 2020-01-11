/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:14:58 by louregni          #+#    #+#             */
/*   Updated: 2018/12/07 17:45:01 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	ft_check_l_f4(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 2) > 19)
		return (0);
	while (++j < 3)
		if (tetr[i + j] != '#')
			return (0);
	j--;
	if ((i + j - 5) >= 0 && tetr[i + j - 5] == '#')
		return (FACE_4);
	if ((i + j + 5) < 20 && tetr[i + j + 5] == '#')
		return (FACE_8);
	return (0);
}

unsigned short	ft_check_l_f3(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 2 * 5) > 19)
		return (0);
	while (j < 3)
	{
		if (tetr[i + j * 5] != '#')
			return (0);
		j++;
	}
	if (tetr[i + 1] == '#')
		return (FACE_7);
	if ((i - 1) >= 0 && tetr[i - 1] == '#')
		return (FACE_3);
	return (0);
}

unsigned short	ft_check_l_f2(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 2) > 19)
		return (0);
	while (j < 3)
	{
		if (tetr[i + j] != '#')
			return (0);
		j++;
	}
	if ((i + 5) < 20 && tetr[i + 5] == '#')
		return (FACE_2);
	if ((i - 5) >= 0 && tetr[i - 5] == '#')
		return (FACE_6);
	return (0);
}

unsigned short	ft_check_l_f1(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 2 * 5) > 19)
		return (0);
	while (j < 3)
	{
		if (tetr[i + (j * 5)] != '#')
			return (0);
		if (j == 2)
		{
			if (tetr[i + (j * 5) + 1] == '#')
				return (FACE_1);
			if (tetr[i + (j * 5) - 1] == '#')
				return (FACE_5);
		}
		j++;
	}
	return (0);
}

unsigned short	ft_check_l(char *tetr)
{
	int				i;
	unsigned short	result;

	i = 0;
	result = LET;
	while (tetr[i] && tetr[i] != '#')
		i++;
	if (!tetr[i])
		return (0);
	if ((result |= ft_check_l_f1(tetr, i)) != LET)
		return (result);
	if ((result |= ft_check_l_f2(tetr, i)) != LET)
		return (result);
	if ((result |= ft_check_l_f2(tetr, i + 5)) != LET)
		return (result);
	if ((result |= ft_check_l_f3(tetr, i)) != LET)
		return (result);
	if ((result |= ft_check_l_f3(tetr, i + 1)) != LET)
		return (result);
	if ((result |= ft_check_l_f4(tetr, i)) != LET)
		return (result);
	if ((result |= ft_check_l_f4(tetr, i + 3)) != LET)
		return (result);
	return (0);
}
