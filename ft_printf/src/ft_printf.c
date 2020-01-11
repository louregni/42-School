/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:38:58 by louregni          #+#    #+#             */
/*   Updated: 2019/02/08 08:12:46 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "p_parser.h"

int		ft_printf(const char *format, ...)
{
	int			result;
	va_list		current;

	va_start(current, format);
	result = ft_parser((char *)format, current);
	va_end(current);
	return (result);
}
