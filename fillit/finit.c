/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:04:28 by louregni          #+#    #+#             */
/*   Updated: 2018/12/07 17:23:03 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "check.h"
#include "fillit.h"

int				get_next_tetrominos(char *buf, char **tetro, ssize_t len)
{
	static int	i = 0;
	int			j;
	int			count;

	count = 0;
	j = i - 1;
	if (buf[i] == '\0')
		return (0);
	while (++j < 20 + i && j < len && buf[j])
		if (((j - i) % 5) == 4 && (buf[j] != '\n' && buf[j] != '\0'))
			return (ft_error(buf, NULL));
		else if ((j - i) % 5 != 4 && (buf[j] != '.' && buf[j] != '#'))
			return (ft_error(buf, NULL));
		else if ((buf[j] == '#' && ++count > 4))
			return (ft_error(buf, NULL));
	if (j != 20 + i)
		return (ft_error(buf, NULL));
	if (count != 4)
		return (ft_error(buf, NULL));
	if (buf[j] != '\0' && ++j >= len && (buf[j] != '.' && buf[j] != '#'))
		return (ft_error(buf, NULL));
	if (!(*tetro = ft_strndup(&buf[i], 20)))
		return (0);
	i = j;
	return (1);
}

unsigned short	ft_get_mask(char *tetr)
{
	unsigned short	mask;

	if ((mask = ft_check_sqr(tetr)))
		return (mask);
	if ((mask = ft_check_line(tetr)))
		return (mask);
	if ((mask = ft_check_s(tetr)))
		return (mask);
	if ((mask = ft_check_t(tetr)))
		return (mask);
	if ((mask = ft_check_l(tetr)))
		return (mask);
	free(tetr);
	return (0);
}

ssize_t			ft_init_buf(char **buf, unsigned short **tab, int fd)
{
	ssize_t	r;

	if (!(*buf = malloc(547 * sizeof(char))))
		return (-1);
	if (!(*tab = malloc(27 * sizeof(short))))
	{
		free(buf);
		return (-1);
	}
	if ((r = read(fd, *buf, 546)) <= 0 || r == 546)
		return (ft_error(*buf, *tab));
	(*buf)[r] = '\0';
	return (r);
}

int				ft_end_list(int nbt, unsigned short *tab, char *buf, int ret)
{
	if (ret == -1)
	{
		free(tab);
		return (-1);
	}
	free(buf);
	tab[nbt] = 0;
	return (nbt);
}

int				ft_get_list(int fd, unsigned short **tab)
{
	int				ret;
	char			*tetro;
	char			*buf;
	int				i;
	ssize_t			len;

	i = 0;
	if ((len = ft_init_buf(&buf, tab, fd)) == -1)
		return (-1);
	while (1)
	{
		if ((ret = get_next_tetrominos(buf, &tetro, len)) < 1)
			return (ft_end_list(i, *tab, buf, ret));
		if (!((*tab)[i] = ft_get_mask(tetro)))
			return (ft_error(buf, *tab));
		free(tetro);
		++i;
	}
	return (42);
}
