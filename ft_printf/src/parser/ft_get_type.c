/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 02:34:22 by louregni          #+#    #+#             */
/*   Updated: 2019/02/14 18:47:02 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_format.h"
#include "d_type.h"

static void		ft_get_type2(char **format, t_percent *obj)
{
	if ((*format)[0] == 'j')
	{
		obj->type |= J;
		*format += 1;
	}
	else if ((*format)[0] == 'L')
	{
		obj->type |= BIGL;
		*format += 1;
	}
	else if ((*format)[0] == 'z')
	{
		obj->type |= Z;
		*format += 1;
	}
}

void			ft_get_type(char **format, t_percent *obj)
{
	if ((*format)[0] == 'h')
	{
		obj->type |= H;
		*format += 1;
		if ((*format)[0] == 'h')
		{
			*format += 1;
			obj->type |= HH;
		}
	}
	else if ((*format)[0] == 'l')
	{
		obj->type |= L;
		*format += 1;
		if ((*format)[0] == 'l')
		{
			*format += 1;
			obj->type |= LL;
		}
	}
	else
		ft_get_type2(format, obj);
}
