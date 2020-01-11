/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 05:17:39 by louregni          #+#    #+#             */
/*   Updated: 2019/02/14 22:05:19 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_type.h"
#include "s_conversion.h"
#include "s_format.h"
#include "p_ischar.h"
#include "p_number.h"

static int	ft_get_conv_ext(char **format, t_percent *obj)
{
	if ((*format)[0] == 'U')
	{
		obj->type = 0;
		obj->type |= L;
		obj->conv = 'u';
		*format += 1;
		return (1);
	}
	return (0);
}

int			ft_get_conv(char **format, t_percent *obj, t_conv *conv)
{
	if (ft_signed(conv, (*format)[0]) || ft_unsigned(conv, (*format)[0]))
	{
		obj->conv = (*format)[0];
		*format += 1;
		return (1);
	}
	else if (ft_ischar(conv, (*format)[0]))
	{
		obj->conv = (*format)[0];
		*format += 1;
		return (1);
	}
	else if ((*format)[0] == 'f')
	{
		obj->conv = (*format)[0];
		*format += 1;
		return (1);
	}
	return (ft_get_conv_ext(format, obj));
}
