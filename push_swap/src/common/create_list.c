/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:39 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:40 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "common.h"

static int	bind_index(t_container *box)
{
	int				*tab;
	unsigned int	i;
	t_list			*tmp;

	if (!(tab = get_tab(box)))
		return (0);
	i = 0;
	tmp = box->a.start;
	quicksort(tab, 0, box->a.size - 1);
	while (i < box->a.size)
	{
		while (tmp->value != tab[i])
			tmp = tmp->next;
		tmp->index = i;
		++i;
	}
	free(tab);
	return (1);
}

int			create_list(t_container *box, int ac, char **av)
{
	ft_bzero(box, sizeof(*box));
	if (!parse(box, ac, av) || box->a.size < 1 || !bind_index(box))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
