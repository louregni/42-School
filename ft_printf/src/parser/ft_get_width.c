/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 01:20:05 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 13:37:53 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "s_format.h"
#include "p_utils.h"

void	ft_get_width(char **format, va_list current, t_percent *obj)
{
	int		count;

	if ((*format)[0] == '*')
	{
		obj->width = va_arg(current, int);
		*format += 1;
	}
	else if (ft_isdigit((*format)[0]) && ft_isint(*format))
	{
		count = -1;
		obj->width = ft_atoi_long(*format);
		while (ft_isdigit((*format)[++count]))
			;
		*format = &(*format)[count];
	}
}
