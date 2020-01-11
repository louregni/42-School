/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:16:57 by louregni          #+#    #+#             */
/*   Updated: 2019/02/03 05:27:02 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "d_flags.h"
#include "s_format.h"
#include "p_str_number.h"
#include "p_utils.h"
#include "p_fill.h"

static void		*ft_get_arg(va_list arg)
{
	void *addr;

	addr = va_arg(arg, void *);
	return (addr);
}

static int		ft_print_pointer(t_percent *obj, char *str, int size)
{
	char charset;

	if (obj->flags & ZERO)
		charset = '0';
	else
		charset = ' ';
	if (!(obj->flags & MINUS))
		ft_fill(obj->width, charset);
	write(1, "0x", 2);
	ft_fill(obj->preci, '0');
	write(1, str, size);
	if (obj->flags & MINUS)
		ft_fill(obj->width, charset);
	return (obj->width + size + 2 + obj->preci);
}

static void		ft_set_format(t_percent *obj, int size)
{
	obj->preci -= size;
	if (obj->preci < 0)
	{
		obj->preci = 0;
		obj->width -= (size + 2);
	}
	else
		obj->width -= (obj->preci + 2 + size);
	if (obj->width < 0)
		obj->width = 0;
}

static int		ft_create_str(t_percent *obj, void *addr)
{
	char	str[65];
	int		size;

	obj->conv = 'x';
	size = ft_str_nbr_base(obj, str, (unsigned long long)addr, 16);
	ft_set_format(obj, size);
	return (ft_print_pointer(obj, str, size));
}

int				ft_get_pointer(t_percent *obj, va_list current, va_list start)
{
	void *addr;

	if (obj->arg_n != 0)
	{
		ft_set_va(obj, start);
		addr = ft_get_arg(start);
	}
	else
		addr = ft_get_arg(current);
	return (ft_create_str(obj, addr));
}
