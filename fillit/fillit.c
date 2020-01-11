/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:25:19 by louregni          #+#    #+#             */
/*   Updated: 2018/12/06 16:26:24 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "search.h"

int		ft_aprox_sqrt(int nb)
{
	int		i;

	if (nb <= 0)
		return (-1);
	if (nb == 4)
		return (2);
	i = 2;
	while (++i)
		if (i * i >= nb)
			return (i);
	return (0);
}

t_sqr	*ft_init_sqr(t_sqr *square, char nbt)
{
	int		i;
	int		len;

	i = -1;
	if (square == NULL)
	{
		if (!(square = malloc(sizeof(t_sqr))))
			return (NULL);
		square->sqr_size = ft_aprox_sqrt(nbt * 4) + 1;
	}
	else
		square->sqr_size += 1;
	square->i = 0;
	len = square->sqr_size * (square->sqr_size - 1);
	if (!(square->sqr = malloc(len + 1)))
		return (NULL);
	while (++i < len)
		if ((i % (square->sqr_size)) == (square->sqr_size - 1))
			square->sqr[i] = '\n';
		else
			square->sqr[i] = '.';
	square->sqr[i] = '\0';
	return (square);
}

t_sqr	*ft_backtrack(unsigned short *tetr, t_sqr *square, char ltr)
{
	int				i;
	t_f				*f;
	unsigned short	*tmp;

	if (*tetr == 0)
		return (square);
	square->i = 0;
	while ((f = ft_isplaceable(square, *tetr)))
	{
		tmp = tetr;
		i = square->i;
		f(square, ltr, &ft_write_tetro);
		if (ft_backtrack(++tmp, square, ltr + 1))
			return (square);
		square->i = i;
		f(square, '.', ft_del_tetro);
		square->i++;
	}
	return (NULL);
}

t_sqr	*ft_fillit(unsigned short *tab, char nbt)
{
	t_sqr	*square;

	square = NULL;
	while (1)
	{
		if (!(square = ft_init_sqr(square, nbt)))
			return (NULL);
		if (ft_backtrack(tab, square, 'A'))
			return (square);
		free(square->sqr);
	}
	return (NULL);
}
