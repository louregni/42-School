/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isplaceable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:48:24 by louregni          #+#    #+#             */
/*   Updated: 2018/12/06 15:53:15 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"
#include "search.h"

int		ft_search(char *c, char ltr)
{
	if (*c == ltr)
		return (0);
	return (1);
}

int		ft_write_tetro(char *c, char ltr)
{
	*c = ltr;
	return (0);
}

int		ft_del_tetro(char *c, char ltr)
{
	*c = ltr;
	return (0);
}

t_f		*ft_find_face(t_sqr *square, unsigned short tetro)
{
	t_f	*f;

	f = NULL;
	if (!(square->sqr[square->i]))
		return (NULL);
	if ((tetro & SQUARE) == SQUARE)
		f = ft_face_sqr(tetro);
	else if ((tetro & LINE) == LINE)
		f = ft_face_line(tetro);
	else if ((tetro & TEA) == TEA)
		f = ft_face_t(tetro);
	else if ((tetro & SNAKE) == SNAKE)
		f = ft_face_s(tetro);
	else if ((tetro & LET) == LET)
		if (!(f = ft_face_l(tetro)))
			f = ft_face_l2(tetro);
	return (f);
}

t_f		*ft_isplaceable(t_sqr *square, unsigned short tetro)
{
	t_f	*f;

	f = ft_find_face(square, tetro);
	if (f == NULL)
		return (NULL);
	while (square->sqr[square->i])
	{
		while (square->sqr[square->i] && square->sqr[square->i] != '.')
			square->i++;
		if (square->sqr[square->i] == '\0')
			return (NULL);
		if (f(square, '.', ft_search))
			return (f);
		square->i++;
	}
	return (NULL);
}
