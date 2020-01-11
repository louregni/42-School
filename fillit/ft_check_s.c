/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:11:23 by ckillian          #+#    #+#             */
/*   Updated: 2018/12/06 14:10:52 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	ft_check_s_f4(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + (2 * 5 - 1)) > 19)
		return (0);
	i += 4;
	if (tetr[i] != '#' || tetr[i + 1] != '#')
		return (0);
	if (tetr[i + 5] != '#')
		return (0);
	return (FACE_4);
}

unsigned short	ft_check_s_f3(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 5 + 2) > 19)
		return (0);
	if (tetr[i] != '#' || tetr[i + 1] != '#')
		return (0);
	i += 6;
	if (tetr[i] != '#' || tetr[i + 1] != '#')
		return (0);
	return (FACE_3);
}

unsigned short	ft_check_s_f2(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 2 * 5 + 1) > 19)
		return (0);
	i += 5;
	if (tetr[i] != '#' || tetr[i + 1] != '#')
		return (0);
	if (tetr[i + 6] != '#')
		return (0);
	return (FACE_2);
}

unsigned short	ft_check_s_f1(char *tetr, int i)
{
	int	j;

	j = 0;
	if ((i + 5 + 1) > 19)
		return (0);
	if (tetr[i + 1] != '#')
		return (0);
	i += 4;
	if (tetr[i] != '#' || tetr[i + 1] != '#')
		return (0);
	return (FACE_1);
}

unsigned short	ft_check_s(char *tetr)
{
	int				i;
	unsigned short	result;

	i = 0;
	result = SNAKE;
	while (tetr[i] && tetr[i] != '#')
		i++;
	if (!tetr[i])
		return (0);
	if ((result |= ft_check_s_f1(tetr, i)) != SNAKE)
		return ((short)result);
	if ((result |= ft_check_s_f2(tetr, i)) != SNAKE)
		return ((short)result);
	if ((result |= ft_check_s_f3(tetr, i)) != SNAKE)
		return ((short)result);
	if ((result |= ft_check_s_f4(tetr, i)) != SNAKE)
		return ((short)result);
	return (0);
}
