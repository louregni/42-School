/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:16:06 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 15:26:17 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "d_flags.h"
#include "s_format.h"
#include "p_fill.h"
#include "p_utils.h"

static char		ft_get_arg(va_list arg)
{
	char	result;

	result = (char)va_arg(arg, int);
	return (result);
}

static void		ft_set_format(t_percent *obj)
{
	obj->width -= 1;
	if ((obj->flags & ZERO) && (obj->flags & MINUS))
		obj->flags ^= ZERO;
	if (obj->width < 0)
		obj->width = 0;
}

static int		ft_print_char(t_percent *obj, char draw)
{
	char charset;
	char c;

	c = 0;
	if (obj->flags & ZERO)
		charset = '0';
	else
		charset = ' ';
	if (!(obj->flags & MINUS))
		ft_fill(obj->width, charset);
	if (draw == 0)
		write(1, &c, 1);
	else
		write(1, &draw, 1);
	if (obj->flags & MINUS)
		ft_fill(obj->width, charset);
	return (obj->width + 1);
}

int				ft_get_char(t_percent *obj, va_list current, va_list start)
{
	char charset;

	if (obj->conv == '%')
		charset = '%';
	else if (obj->arg_n != 0)
	{
		ft_set_va(obj, start);
		charset = ft_get_arg(start);
	}
	else
		charset = ft_get_arg(current);
	ft_set_format(obj);
	return (ft_print_char(obj, charset));
}
