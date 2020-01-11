/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:16:51 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 15:17:25 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "d_flags.h"
#include "p_utils.h"
#include "p_fill.h"
#include "s_format.h"

static char		*ft_get_arg(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	return (str);
}

static int		ft_print_string(t_percent *obj, char *str)
{
	char	charset;

	if (obj->flags & ZERO)
		charset = '0';
	else
		charset = ' ';
	if (!(obj->flags & MINUS))
		ft_fill(obj->width, charset);
	if (str == 0)
		return (write(1, "(null)", 6));
	write(1, str, obj->preci);
	if (obj->flags & MINUS)
		ft_fill(obj->width, charset);
	if (str == 0)
		return (6);
	return (obj->width + obj->preci);
}

static void		ft_set_format(t_percent *obj, int size)
{
	if (obj->preci == -1)
		obj->preci = size;
	else if (obj->preci > size)
		obj->preci = size;
	obj->width -= obj->preci;
	if (obj->width < 0)
		obj->width = 0;
}

int				ft_get_string(t_percent *obj, va_list current,
		va_list start)
{
	char		*str;
	int			size;

	size = 0;
	if (obj->arg_n != 0)
	{
		ft_set_va(obj, start);
		str = ft_get_arg(start);
	}
	else
		str = ft_get_arg(current);
	if (str != 0)
		size = ft_strlen(str);
	ft_set_format(obj, size);
	return (ft_print_string(obj, str));
}
