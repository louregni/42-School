/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 05:44:30 by louregni          #+#    #+#             */
/*   Updated: 2019/02/01 07:23:19 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "s_conversion.h"
#include "s_format.h"
#include "p_get_format.h"

int	ft_get_format(char **format, va_list current, t_percent *obj, t_conv *conv)
{
	ft_check_dollar(format, obj);
	ft_check_flags(format, obj);
	ft_get_width(format, current, obj);
	ft_get_precision(format, current, obj);
	ft_get_type(format, obj);
	if (!(ft_get_conv(format, obj, conv)))
	{
		write(1, "%", 1);
		return (0);
	}
	return (1);
}
