/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 04:48:18 by louregni          #+#    #+#             */
/*   Updated: 2019/02/08 10:27:21 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "d_type.h"
#include "s_format.h"
#include "s_conversion.h"
#include "p_number.h"
#include "p_utils.h"

long long		ft_get_value(t_percent *obj, va_list arg)
{
	long long	value;

	if (obj->type & HH)
		value = (char)va_arg(arg, int);
	else if (obj->type & H)
		value = (short int)va_arg(arg, int);
	else if (obj->type & LL || obj->type & J)
		value = va_arg(arg, long long);
	else if (obj->type & L)
		value = va_arg(arg, long);
	else if (obj->type & Z)
		value = va_arg(arg, size_t);
	else
		value = va_arg(arg, int);
	return (value);
}

long long		ft_convert(t_conv *conv, t_percent *obj, long long value)
{
	if (ft_unsigned(conv, obj->conv) && obj->type == 0)
		value = (unsigned int)value;
	else if (ft_unsigned(conv, obj->conv) && (obj->type & HH))
		value = (unsigned char)value;
	else if (ft_unsigned(conv, obj->conv) && (obj->type & H))
		value = (unsigned short int)value;
	else if (ft_unsigned(conv, obj->conv) && (obj->type & LL))
		return (value);
	else if (ft_unsigned(conv, obj->conv) && (obj->type & L))
		value = (unsigned long)value;
	else if (ft_unsigned(conv, obj->conv) && (obj->type & J))
		value = (unsigned long long)value;
	return (value);
}

long long		ft_get_arg_value(t_conv *conv, t_percent *obj,
		va_list current, va_list start)
{
	long long value;

	if (obj->arg_n != 0)
	{
		ft_set_va(obj, start);
		value = ft_get_value(obj, start);
	}
	else
		value = ft_get_value(obj, current);
	value = ft_convert(conv, obj, value);
	return (value);
}
