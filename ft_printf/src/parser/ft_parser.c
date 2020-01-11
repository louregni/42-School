/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:43:25 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 13:25:24 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "d_info.h"
#include "s_modifier.h"
#include "p_modifier.h"

static int	(*ft_check_modifier(char charset, t_modifier *modifiers))()
{
	ssize_t	count;

	count = -1;
	while (++count < NB_MODI)
	{
		if (charset == modifiers[count].charset)
			return (modifiers[count].ft_parsing);
	}
	return (NULL);
}

static int	ft_parsing(char *format, va_list current, va_list start,
			t_modifier *modifiers)
{
	va_list		tmp;
	int			count;
	int			nb_chars;
	int			(*fct_parse)();

	count = -1;
	nb_chars = 0;
	va_copy(start, current);
	va_copy(tmp, start);
	while (format[++count])
	{
		if ((fct_parse = ft_check_modifier(format[count], modifiers)) != NULL)
		{
			write(1, format, count);
			format += (count + 1);
			nb_chars += fct_parse(&format, current, tmp);
			va_end(tmp);
			count = -1;
		}
		else
			++nb_chars;
	}
	write(1, format, count);
	return (nb_chars);
}

int			ft_parser(char *format, va_list current)
{
	char		nb_chars;
	va_list		start;
	t_modifier	modifiers[NB_MODI];

	ft_init_modifier(modifiers);
	nb_chars = ft_parsing(format, current, start, modifiers);
	va_end(start);
	return (nb_chars);
}
