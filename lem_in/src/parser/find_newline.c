/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:53:17 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:53:17 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "find.h"

static unsigned long long inline	find_height(unsigned long long key)
{
	return ((key - 0x0101010101010101ULL)
			& ~(key) & 0x8080808080808080ULL);
}

static unsigned int inline			find_four(unsigned int key)
{
	return ((key - (unsigned int)0x01010101)
			& ~(key) & (unsigned int)0x80808080);
}

static unsigned short inline		find_two(unsigned short key)
{
	return ((key - (unsigned short)0x0101)
			& ~(key) & (unsigned short)0x8080);
}

inline int							find_newline(t_read *reader)
{
	while (1)
	{
		if (!reader->size && read_entry(reader))
			return (-1);
		while (reader->size > 7
				&& !find_height(*((unsigned long long *)reader->ptr)
					^ FIND_NEWLINE_8))
			update_reader(reader, 8);
		if (reader->size > 3
				&& !find_four(*((unsigned int *)reader->ptr) ^ FIND_NEWLINE_4))
			update_reader(reader, 4);
		if (reader->size > 1
				&& !find_two(*((unsigned short int *)reader->ptr)
					^ FIND_NEWLINE_2))
			update_reader(reader, 2);
		if (reader->size > 0)
		{
			if (*reader->ptr == '\n')
			{
				update_reader(reader, 1);
				return (0);
			}
			update_reader(reader, 1);
		}
	}
}
