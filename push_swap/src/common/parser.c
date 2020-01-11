/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:50 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:51 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

int			is_sort(t_list *start)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = start;
	tmp2 = tmp->next;
	while (tmp2 != start)
	{
		if (tmp->value > tmp2->value)
			return (0);
		tmp2 = tmp2->next;
		tmp = tmp->next;
	}
	return (1);
}

int			*get_tab(t_container *box)
{
	int				*tab;
	unsigned int	i;
	t_list			*tmp;

	if (!(tab = malloc(sizeof(*tab) * box->a.size)))
		return (0);
	i = 0;
	tmp = box->a.start;
	while (i < box->a.size)
	{
		tab[i] = tmp->value;
		++i;
		tmp = tmp->next;
	}
	return (tab);
}

static int	have_duplicate(t_list *elem)
{
	t_list *save;

	save = elem;
	elem = elem->next;
	while (elem != save)
	{
		if (elem->value == save->value)
			return (1);
		elem = elem->next;
	}
	return (0);
}

int			parse(t_container *box, int ac, char **av)
{
	t_list	*tmp;
	int		result;
	int		ret;
	int		i;

	i = 0;
	while (++i < ac)
	{
		while (*av[i] == ' ')
			++av[i];
		while ((ret = get_number(&av[i], &result)) == 1)
		{
			if (!(tmp = malloc(sizeof(t_list))))
				return (0);
			tmp->value = result;
			push_list(&box->a.start, tmp);
			++box->a.size;
			if (have_duplicate(tmp))
				return (0);
		}
		if (ret == 0)
			return (0);
	}
	return (1);
}
