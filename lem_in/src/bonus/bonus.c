/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:55:55 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:55:55 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "print.h"
#include "utils.h"

void	enter_color(t_id *id, t_name *name)
{
	write(1, "\e[38;5;39m", 10);
	write(1, id->ptr, 1);
	write(1, "\e[38;5;84m", 10);
	write(1, id->ptr + 1, id->size - 2);
	write(1, "\e[38;5;39m", 10);
	write(1, id->ptr + id->size - 1, 1);
	write(1, "\e[38;5;87m", 10);
	write(1, name->name, name->size);
	write(1, " ", 1);
	write(1, "\e[0m", 4);
}

void	leave_color(t_id *id, t_name *name)
{
	write(1, "\e[38;5;81m", 10);
	write(1, id->ptr, 1);
	write(1, "\e[38;5;227m", 11);
	write(1, id->ptr + 1, id->size - 2);
	write(1, "\e[38;5;81m", 10);
	write(1, id->ptr + id->size - 1, 1);
	write(1, "\e[38;5;82m", 10);
	write(1, name->name, name->size);
	write(1, " ", 1);
	write(1, "\e[0m", 4);
}

void	classic(t_id *id, t_name *name)
{
	write(1, "\e[38;5;69m;", 10);
	write(1, id->ptr, 1);
	write(1, "\e[38;5;72m", 11);
	write(1, id->ptr + 1, id->size - 2);
	write(1, "\e[38;5;69m", 10);
	write(1, id->ptr + id->size - 1, 1);
	write(1, "\e[38;5;92m", 10);
	write(1, name->name, name->size);
	write(1, " ", 1);
	write(1, "\e[0m", 4);
}

void	show_lines(unsigned int lines, unsigned int flags)
{
	t_id	result;

	ft_itoa(lines, &result);
	if (flags & COLOR)
		write(1, "\e[32mNumber of lines : ", 23);
	else
		write(1, "Number of lines : ", 18);
	write(1, result.ptr, result.size);
	write(1, "\n", 1);
}
