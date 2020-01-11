/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:50:46 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:50:47 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "utils.h"

static inline int	sepchr(unsigned char *str, int size, unsigned char sep)
{
	int	i;

	i = 0;
	while (i < size && i < (WORD_SIZE + 1))
	{
		if (str[i] == sep)
			return (i);
		else if (str[i] < '!' || str[i] > '~' || str[i] == '-')
			return (-2);
		++i;
	}
	return (-1);
}

static inline int	enough(t_read *reader, t_link *name, unsigned char sep)
{
	int	pos;

	if ((pos = sepchr(reader->ptr, reader->size, sep)) < 1)
		return (-1);
	name->size = pos;
	ft_memcpy(name->name, reader->ptr, pos);
	update_reader(reader, (pos + 1));
	return (0);
}

static inline int	not_enough(t_read *reader, t_link *name,
		unsigned char sep, int limit)
{
	int	pos;

	while (1)
	{
		if (!reader->size && read_entry(reader))
			return (-1);
		limit = ((unsigned int)reader->size > (WORD_SIZE - name->size)
				? (WORD_SIZE - name->size) : reader->size);
		if ((pos = sepchr(reader->ptr, limit, sep)) < -1
				|| (!name->size && !pos))
			return (-1);
		if (pos == -1)
		{
			if ((limit + name->size) > WORD_SIZE)
				return (-1);
			ft_memcpy(name->name + name->size, reader->ptr, limit);
			name->size += limit;
			update_reader(reader, limit);
			continue;
		}
		ft_memcpy(name->name + name->size, reader->ptr, pos);
		name->size += pos;
		update_reader(reader, pos + 1);
		return (0);
	}
}

int					get_name(t_read *reader, t_link *name, unsigned char sep)
{
	int		pos;

	if (!reader->size && read_entry(reader))
		return (-1);
	if (reader->size > WORD_SIZE)
		return (enough(reader, name, sep));
	if ((pos = sepchr(reader->ptr, reader->size, sep)) < -1 || !pos)
		return (-1);
	if (pos > 0)
		return (enough(reader, name, sep));
	ft_memcpy(name->name, reader->ptr, reader->size);
	name->size = reader->size;
	reader->size = 0;
	return (not_enough(reader, name, sep, 0));
}
