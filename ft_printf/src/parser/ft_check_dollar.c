/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:05:44 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 13:32:20 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_format.h"
#include "p_utils.h"

void	ft_check_dollar(char **format, t_percent *obj)
{
	int		count;
	int		arg;

	if (ft_isdigit((*format)[0]) && (*format)[0] > '0')
	{
		count = 0;
		while (ft_isdigit((*format)[++count]))
			;
		if ((*format)[count] == '$' && (arg = ft_isint(*format)))
		{
			obj->arg_n = ft_atoi_long(*format);
			*format = &(*format)[count + 1];
		}
	}
}
