/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:18:22 by louregni          #+#    #+#             */
/*   Updated: 2019/02/14 18:50:52 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "d_info.h"
#include "s_format.h"
#include "s_conversion.h"
#include "s_double.h"
#include "p_number.h"
#include "p_create.h"
#include "p_print_nbr.h"
#include "p_ischar.h"
#include "p_chars.h"
#include "p_double.h"

static int		ft_number(t_conv *conv, t_percent *obj, va_list current,
		va_list start)
{
	int			size;
	long long	nbr;

	nbr = ft_get_arg_value(conv, obj, current, start);
	size = ft_print_number(obj, conv, nbr);
	return (size);
}

static int		ft_char(t_conv *conv, t_percent *obj, va_list current,
		va_list start)
{
	int		count;
	int		(*fct_print)(t_percent *obj, va_list current, va_list start);

	count = -1;
	while (++count < NB_CHAR)
	{
		if (obj->conv == conv->charset[count].conv)
		{
			fct_print = conv->charset[count].ft_print;
			return (fct_print(obj, current, start));
		}
	}
	return (0);
}

static int		ft_double(t_percent *obj, va_list current, va_list start)
{
	int			size;
	t_double	ptr;
	long double value;

	value = ft_get_double(obj, current, start);
	size = ft_print_double(obj, &ptr, value);
	return (size);
}

int				ft_print(t_conv *conv, t_percent *obj, va_list current,
		va_list start)
{
	int		size;

	size = 0;
	if (ft_signed(conv, obj->conv) || ft_unsigned(conv, obj->conv))
		size = ft_number(conv, obj, current, start);
	else if (ft_ischar(conv, obj->conv))
		size = ft_char(conv, obj, current, start);
	else if (obj->conv == 'f')
		size = ft_double(obj, current, start);
	return (size);
}
