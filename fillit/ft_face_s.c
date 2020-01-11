/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_face_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:19:18 by ckillian          #+#    #+#             */
/*   Updated: 2018/12/06 16:20:54 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int	ft_face_s_f4(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	if ((square->i + 2 * square->sqr_size - 1) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	if (f(&(square->sqr[square->i]), ltr))
		return (0);
	j = square->sqr_size - 1;
	if (f(&(square->sqr[square->i + j]), ltr))
		return (0);
	if (f(&(square->sqr[square->i + j + 1]), ltr))
		return (0);
	j += square->sqr_size;
	if (f(&(square->sqr[square->i + j]), ltr))
		return (0);
	return (1);
}

int	ft_face_s_f3(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	if ((square->i + square->sqr_size + 2) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	if (f(&(square->sqr[square->i]), ltr) ||
										f(&(square->sqr[square->i + 1]), ltr))
		return (0);
	j = square->sqr_size + 1;
	if (f(&(square->sqr[square->i + j]), ltr) ||
									f(&(square->sqr[square->i + j + 1]), ltr))
		return (0);
	return (1);
}

int	ft_face_s_f2(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	if ((square->i + 2 * square->sqr_size + 1) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	if (f(&(square->sqr[square->i]), ltr))
		return (0);
	j = square->sqr_size;
	if (f(&(square->sqr[square->i + j]), ltr))
		return (0);
	if (f(&(square->sqr[square->i + j + 1]), ltr))
		return (0);
	j += square->sqr_size;
	if (f(&(square->sqr[square->i + j + 1]), ltr))
		return (0);
	return (1);
}

int	ft_face_s_f1(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	j = 0;
	if ((square->i + square->sqr_size) >=
							(square->sqr_size * (square->sqr_size - 1) - 1))
		return (0);
	if (f(&(square->sqr[square->i]), ltr))
		return (0);
	if (f(&(square->sqr[square->i + 1]), ltr))
		return (0);
	j = square->sqr_size - 1;
	if (f(&(square->sqr[square->i + j]), ltr))
		return (0);
	if (f(&(square->sqr[square->i + j + 1]), ltr))
		return (0);
	return (1);
}

t_f	*ft_face_s(unsigned short tetro)
{
	if ((tetro & FACE_1) == FACE_1)
		return (ft_face_s_f1);
	if ((tetro & FACE_2) == FACE_2)
		return (ft_face_s_f2);
	if ((tetro & FACE_3) == FACE_3)
		return (ft_face_s_f3);
	if ((tetro & FACE_4) == FACE_4)
		return (ft_face_s_f4);
	return (NULL);
}
