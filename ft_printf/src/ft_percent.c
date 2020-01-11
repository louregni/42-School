/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:57:47 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 13:25:25 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "s_conversion.h"
#include "s_format.h"
#include "p_conversion.h"
#include "p_get_format.h"
#include "p_print.h"

static void		ft_init_format(t_percent *obj)
{
	obj->arg_n = 0;
	obj->flags = 0;
	obj->width = -1;
	obj->preci = -1;
	obj->type = 0;
	obj->conv = 0;
}

int				ft_percent(char **format, va_list current, va_list start)
{
	int			size;
	t_conv		conv;
	t_percent	obj;

	ft_init_convert(&conv);
	ft_init_format(&obj);
	if (!(ft_get_format(format, current, &obj, &conv)))
		return (0);
	size = ft_print(&conv, &obj, current, start);
	return (size);
}
