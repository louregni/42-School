/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:34:40 by louregni          #+#    #+#             */
/*   Updated: 2019/02/03 00:13:58 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_format.h"
#include "d_flags.h"

void	ft_check_flags(char **format, t_percent *obj)
{
	int		count;

	count = -1;
	while (1)
	{
		++count;
		if ((*format)[count] == ' ')
			obj->flags |= SPACE;
		else if ((*format)[count] == '#')
			obj->flags |= DIEZ;
		else if ((*format)[count] == '0')
			obj->flags |= ZERO;
		else if ((*format)[count] == '-')
			obj->flags |= MINUS;
		else if ((*format)[count] == '+')
			obj->flags |= PLUS;
		else if ((*format)[count] == '\'')
			obj->flags |= QUOTE;
		else
		{
			*format = &(*format)[count];
			return ;
		}
	}
}
