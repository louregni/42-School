/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_face_sqr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:39:15 by louregni          #+#    #+#             */
/*   Updated: 2018/12/06 14:26:07 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

int	ft_face_sqr_f1(t_sqr *square, char ltr, int (*f)(char *, char))
{
	if (f(&(square->sqr[square->i]), ltr))
		return (0);
	if (f(&(square->sqr[square->i + 1]), ltr))
		return (0);
	if ((square->i + square->sqr_size + 1) >
							(square->sqr_size * (square->sqr_size - 1) - 1) ||
						f(&square->sqr[square->i + square->sqr_size + 1], ltr))
		return (0);
	if (f(&square->sqr[square->i + square->sqr_size], ltr))
		return (0);
	return (1);
}

t_f	*ft_face_sqr(unsigned short tetro)
{
	if ((tetro & FACE_1) == FACE_1)
		return (ft_face_sqr_f1);
	return (NULL);
}
