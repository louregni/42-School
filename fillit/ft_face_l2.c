/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_face_l2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:57:35 by ckillian          #+#    #+#             */
/*   Updated: 2018/12/06 14:26:48 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int	ft_face_l2_f4(t_sqr *square, char ltr, int (*f)(char *, char))
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
		if (j == 2)
			if (f(&(square->sqr[square->i + j + square->sqr_size]), ltr))
				return (0);
		j++;
	}
	return (1);
}

int	ft_face_l2_f3(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	j = 0;
	if ((square->i + 2 * square->sqr_size) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	if (f(&(square->sqr[square->i + 1]), ltr))
		return (0);
	while (j < 3)
	{
		if (f(&(square->sqr[square->i + (j * square->sqr_size)]), ltr))
			return (0);
		j++;
	}
	return (1);
}

int	ft_face_l2_f2(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	j = 0;
	if ((square->i + square->sqr_size + 2) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	if (f(&(square->sqr[square->i]), ltr))
		return (0);
	while (j < 3)
	{
		if (f(&(square->sqr[square->i + j + square->sqr_size]), ltr))
			return (0);
		j++;
	}
	return (1);
}

int	ft_face_l2_f1(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	j = 0;
	if ((square->i + 2 * square->sqr_size) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	while (j < 3)
	{
		if (f(&(square->sqr[square->i + j * square->sqr_size]), ltr))
			return (0);
		if (j == 2)
			if (f(&(square->sqr[square->i + j * square->sqr_size - 1]), ltr))
				return (0);
		j++;
	}
	return (1);
}

t_f	*ft_face_l2(unsigned short tetro)
{
	if ((tetro & FACE_5) == FACE_5)
		return (ft_face_l2_f1);
	if ((tetro & FACE_6) == FACE_6)
		return (ft_face_l2_f2);
	if ((tetro & FACE_7) == FACE_7)
		return (ft_face_l2_f3);
	if ((tetro & FACE_8) == FACE_8)
		return (ft_face_l2_f4);
	return (NULL);
}
