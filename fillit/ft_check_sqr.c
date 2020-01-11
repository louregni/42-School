/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sqr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:22:12 by louregni          #+#    #+#             */
/*   Updated: 2018/12/06 14:10:12 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	ft_check_sqr_f1(char *testr, int i)
{
	if (testr[i + 1] != '#')
		return (0);
	if ((i + 6) > 19 || testr[i + 6] != '#')
		return (0);
	if (testr[i + 5] != '#')
		return (0);
	return (FACE_1);
}

unsigned short	ft_check_sqr(char *tetr)
{
	int				i;
	unsigned short	result;

	i = 0;
	result = SQUARE;
	while (tetr[i] && tetr[i] != '#')
		i++;
	if (!tetr[i])
		return (0);
	if ((result |= ft_check_sqr_f1(tetr, i)) != SQUARE)
		return (result);
	return (0);
}
