/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 01:33:10 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 13:37:42 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "p_utils.h"
#include "s_format.h"

void	ft_get_precision(char **format, va_list current, t_percent *obj)
{
	int		count;

	if ((*format)[0] != '.')
		return ;
	*format += 1;
	if ((*format)[0] == '*')
	{
		obj->preci = va_arg(current, int);
		*format += 1;
	}
	else if (!ft_isdigit((*format)[0]))
		obj->preci = 0;
	else if (ft_isdigit((*format)[0]) && ft_isint(*format))
	{
		count = -1;
		obj->preci = ft_atoi_long(*format);
		while (ft_isdigit((*format)[++count]))
			;
		*format = &(*format)[count];
	}
}
