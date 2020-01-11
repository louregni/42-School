/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:00:17 by louregni          #+#    #+#             */
/*   Updated: 2018/12/07 17:47:56 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "finit.h"
#include "fillit.h"

int		ft_error(char *buf, unsigned short *tab)
{
	if (buf)
		free(buf);
	if (tab)
		free(tab);
	write(1, "error\n", 6);
	return (-1);
}

int		ft_print_usg(void)
{
	ft_putstr("usage : fillit <file>\n");
	return (0);
}

int		main(int ac, char **av)
{
	int				fd;
	unsigned short	*tab;
	int				nbt;
	t_sqr			*square;

	tab = NULL;
	if (ac != 2)
		return (ft_print_usg());
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_error(NULL, NULL));
	if ((nbt = ft_get_list(fd, &tab)) < 1)
		return (-1);
	square = ft_fillit(tab, nbt);
	free(tab);
	ft_putstr(square->sqr);
	free(square->sqr);
	free(square);
	close(fd);
	return (0);
}
