/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_va.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 05:50:27 by louregni          #+#    #+#             */
/*   Updated: 2019/02/01 08:54:21 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "s_format.h"

void		ft_set_va(t_percent *obj, va_list start)
{
	int		count;

	count = 0;
	while (++count < obj->arg_n)
		va_arg(start, int);
}
