/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:50:53 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:50:54 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "utils.h"

static inline int	sepchr(unsigned char *str, int size, unsigned char *result)
{
	int	i;

	i = 0;
	while (i < size && i < (WORD_SIZE + 1))
	{
		if (str[i] == ' ' || str[i] == '-')
		{
			*result = str[i];
			return (i);
		}
		else if (str[i] < '!' || str[i] > '~')
			return (-2);
		++i;
	}
	return (-1);
}

static inline int	enough(t_read *reader, unsigned int limit, t_name *name)
{
	int				pos;
	unsigned char	result;

	if ((pos = sepchr(reader->ptr, limit, &result)) < 1)
		return (-1);
	if (!(name->name = malloc(sizeof(char) * pos)))
		return (-1);
	ft_memcpy(name->name, reader->ptr, pos);
	name->size = pos;
	update_reader(reader, (pos + 1));
	if (result == ' ')
		return (0);
	return (1);
}

static inline int	create_update(t_read *reader, t_name *name,
		unsigned char tmp[], int pos)
{
	if (!(name->name = malloc(sizeof(char) * (pos + name->size))))
		return (-1);
	ft_memcpy(name->name, tmp, name->size);
	ft_memcpy(name->name + name->size, reader->ptr, pos);
	name->size += pos;
	update_reader(reader, pos + 1);
	return (0);
}

static inline int	not_enough(t_read *reader,
		t_name *name, unsigned char tmp[])
{
	int				pos;
	int				limit;
	unsigned char	sep;

	while (1)
	{
		if (!reader->size && read_entry(reader))
			return (-1);
		limit = ((unsigned int)reader->size > (WORD_SIZE - name->size)
				? (WORD_SIZE - name->size) : reader->size);
		if ((pos = sepchr(reader->ptr, limit, &sep)) < -1
				|| (pos == -1 && ((limit + name->size) > WORD_SIZE)))
			return (-1);
		if (pos == -1)
		{
			ft_memcpy(tmp + name->size, reader->ptr, limit);
			name->size += limit;
			update_reader(reader, limit);
			continue ;
		}
		if (((pos + name->size) > WORD_SIZE)
				|| create_update(reader, name, tmp, pos) == -1)
			return (-1);
		return (sep == ' ' ? 0 : 1);
	}
}

int					get_node_name(t_read *reader, t_name *name)
{
	unsigned char	sep;
	int				pos;
	unsigned char	tmp[WORD_SIZE];

	if (!reader->size && read_entry(reader))
		return (-1);
	if (reader->size > WORD_SIZE)
		return (enough(reader, WORD_SIZE, name));
	name->size = reader->size;
	sep = -1;
	if ((pos = sepchr(reader->ptr, reader->size, &sep)) < -1 || !pos)
		return (-1);
	if (pos > 0)
		return (enough(reader, pos + 1, name));
	ft_memcpy(tmp, reader->ptr, reader->size);
	name->size = reader->size;
	reader->size = 0;
	return (not_enough(reader, name, tmp));
}
