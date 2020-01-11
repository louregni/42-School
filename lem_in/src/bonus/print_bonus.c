/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:55:34 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:55:36 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "print.h"

void			print_leave(t_id *id, t_name *name, unsigned int flags)
{
	if (flags & COLOR)
		leave_color(id, name);
	else
	{
		write(1, id->ptr, id->size);
		write(1, name->name, name->size);
		write(1, " ", 1);
	}
}

void			print_enter(t_id *id, t_name *name, unsigned int flags)
{
	if (flags & COLOR)
		enter_color(id, name);
	else
	{
		write(1, id->ptr, id->size);
		write(1, name->name, name->size);
		write(1, " ", 1);
	}
}

inline void		print_ant(t_id *id, t_name *name)
{
	write(1, id->ptr, id->size);
	write(1, name->name, name->size);
	write(1, " ", 1);
}
