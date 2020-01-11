/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_face_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:53:17 by louregni          #+#    #+#             */
/*   Updated: 2018/12/07 17:53:21 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int		ft_face_line_f2(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	j = 0;
	if ((square->i + 3 * square->sqr_size) >=
										(square->sqr_size * square->sqr_size))
		return (0);
	while (j < 4)
	{
		if (f(&(square->sqr[square->i + (j * square->sqr_size)]), ltr))
			return (0);
		j++;
	}
	return (1);
}

int		ft_face_line_f1(t_sqr *square, char ltr, int (*f)(char *, char))
{
	int	j;

	j = 0;
	if ((square->i + 3) >= (square->sqr_size * square->sqr_size))
		return (0);
	while (j < 4)
		if (f(&(square->sqr[square->i + j++]), ltr))
			return (0);
	return (1);
}

t_f		*ft_face_line(unsigned short tetro)
{
	if ((tetro & FACE_1) == FACE_1)
		return (ft_face_line_f1);
	if ((tetro & FACE_2) == FACE_2)
		return (ft_face_line_f2);
	return (NULL);
}
