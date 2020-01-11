/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_face_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:52:17 by ckillian          #+#    #+#             */
/*   Updated: 2018/12/06 14:25:21 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int	ft_face_l_f4(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	j = 0;
	if ((square->i + square->sqr_size) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	if (f(&(square->sqr[square->i]), ltr))
		return (0);
	while (j < 3)
	{
		if (f(&(square->sqr[square->i + square->sqr_size - j]), ltr))
			return (0);
		j++;
	}
	return (1);
}

int	ft_face_l_f3(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	j = 0;
	if ((square->i + 2 * square->sqr_size + 1) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	if (f(&(square->sqr[square->i]), ltr))
		return (0);
	while (j < 3)
	{
		if (f(&(square->sqr[square->i + j * square->sqr_size + 1]), ltr))
			return (0);
		j++;
	}
	return (1);
}

int	ft_face_l_f2(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	j = 0;
	if ((square->i + square->sqr_size) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	while (j < 3)
	{
		if (f(&(square->sqr[square->i + j]), ltr))
			return (0);
		if (j == 0)
			if (f(&(square->sqr[square->i + j + square->sqr_size]), ltr))
				return (0);
		j++;
	}
	return (1);
}

int	ft_face_l_f1(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	j = 0;
	if ((square->i + (2 * square->sqr_size) + 1) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	while (j < 3)
	{
		if (f(&(square->sqr[square->i + j * square->sqr_size]), ltr))
			return (0);
		if (j == 2)
			if (f(&(square->sqr[square->i + j * square->sqr_size + 1]), ltr))
				return (0);
		j++;
	}
	return (1);
}

t_f	*ft_face_l(unsigned short tetro)
{
	if ((tetro & FACE_1) == FACE_1)
		return (ft_face_l_f1);
	if ((tetro & FACE_2) == FACE_2)
		return (&ft_face_l_f2);
	if ((tetro & FACE_3) == FACE_3)
		return (ft_face_l_f3);
	if ((tetro & FACE_4) == FACE_4)
		return (ft_face_l_f4);
	return (NULL);
}
