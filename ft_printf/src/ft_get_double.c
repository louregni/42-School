/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:12:08 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 13:33:39 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "d_type.h"
#include "s_format.h"
#include "p_utils.h"

long double		ft_get_double(t_percent *obj, va_list current, va_list start)
{
	long double value;

	if (obj->arg_n != 0)
	{
		ft_set_va(obj, start);
		if (obj->type & BIGL)
			value = va_arg(start, long double);
		else
			value = va_arg(start, double);
	}
	else
	{
		if (obj->type & BIGL)
			value = va_arg(current, long double);
		else
			value = va_arg(current, double);
	}
	return (value);
}
