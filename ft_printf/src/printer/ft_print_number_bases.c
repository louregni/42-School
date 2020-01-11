/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_bases.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 11:33:57 by louregni          #+#    #+#             */
/*   Updated: 2019/02/06 13:59:21 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "d_flags.h"
#include "s_print.h"
#include "s_format.h"
#include "p_fill.h"

static void			ft_patch(t_percent *obj, t_print *print)
{
	if (obj->flags & SPACE && obj->flags & PLUS)
		obj->flags ^= SPACE;
	if (obj->flags & ZERO && obj->flags & MINUS)
		obj->flags ^= ZERO;
	if (obj->preci > -1 && obj->flags & ZERO)
		obj->flags ^= ZERO;
	if (obj->preci > 0 && print->size > obj->preci)
		print->preci = 0;
	else if (obj->preci > 0)
		print->preci = obj->preci - print->size;
	else
		print->preci = 0;
	if (print->preci >= obj->width)
		print->width = 0;
	else if (obj->width > 0)
	{
		print->width = (obj->flags & PLUS || obj->sign == '-')
								? obj->width - 1 : obj->width;
		if (obj->preci != 0)
			print->width -= print->preci + (print->size);
	}
	if (obj->flags & DIEZ)
		print->width -= (obj->conv == 'o') ? 1 : 2;
	print->width = (print->width < 0) ? 0 : print->width;
	print->preci = (print->preci < 0) ? 0 : print->preci;
}

static int			ft_write_hex(t_percent *obj, t_print *print)
{
	if (!(obj->flags & DIEZ))
		return (0);
	if (print->str[0] == '0')
		return (0);
	if (obj->conv == 'o')
		return (write(1, "0", 1));
	write(1, "0", 1);
	write(1, &obj->conv, 1);
	return (2);
}

int					ft_print_nbr_bases(t_percent *obj, t_print *print)
{
	char	charset;
	int		bonus;

	ft_patch(obj, print);
	charset = (obj->flags & ZERO) ? '0' : ' ';
	obj->sign = (obj->flags & SPACE && obj->sign == '+') ? ' ' :
		obj->sign;
	if (obj->flags & ZERO)
		bonus = ft_write_hex(obj, print);
	if (!(obj->flags & MINUS))
		ft_fill(print->width, charset);
	if (!(obj->flags & ZERO))
		bonus = ft_write_hex(obj, print);
	ft_fill(print->preci, '0');
	if (obj->preci != 0 || (obj->flags & DIEZ && obj->conv == 'o'))
		write(1, print->str, print->size);
	else
		bonus -= 1;
	if (obj->flags & MINUS)
		ft_fill(print->width, charset);
	return (print->width + print->preci + print->size + bonus);
}
