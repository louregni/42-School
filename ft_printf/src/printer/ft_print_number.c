/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:29:35 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 15:11:48 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "d_flags.h"
#include "s_print.h"
#include "s_format.h"
#include "s_conversion.h"
#include "p_utils.h"
#include "p_str_number.h"
#include "p_number.h"
#include "p_fill.h"
#include "p_print_nbr_bases.h"

static void		ft_patch(t_percent *obj, t_print *print)
{
	if (obj->flags & ZERO && obj->flags & MINUS)
		obj->flags ^= ZERO;
	if (obj->flags & SPACE && obj->flags & PLUS)
		obj->flags ^= SPACE;
	if (obj->preci > 0 && print->size > obj->preci)
		print->preci = 0;
	else if (obj->preci > 0)
		print->preci = obj->preci - print->size;
	else
		print->preci = 0;
	print->width = (print->preci >= obj->width) ? 0 : obj->width;
	obj->sign = (obj->flags & SPACE && obj->sign == '+') ? ' ' : obj->sign;
	if (obj->width > 0)
	{
		print->width = ((obj->flags & PLUS || obj->flags & SPACE) ||
						obj->sign == '-') ? obj->width - 1 : obj->width;
		print->width -= (print->preci + print->size);
		print->width = (print->width < 0) ? 0 : print->width;
	}
	if (obj->preci == 0 && print->str[0] == '0')
	{
		print->width = (obj->width == -1) ? print->width : print->width + 1;
		print->size = 0;
	}
}

static int		ft_print_nbr(t_percent *obj, t_print *print)
{
	char	charset;
	int		bonus;

	if (obj->preci > -1 && obj->flags & ZERO)
		obj->flags ^= ZERO;
	ft_patch(obj, print);
	bonus = 0;
	charset = (obj->flags & ZERO) ? '0' : ' ';
	if (((obj->flags & PLUS || obj->flags & SPACE) || obj->sign == '-') &&
						obj->flags & ZERO && obj->conv != 'u')
		bonus += write(1, &obj->sign, 1);
	if (!(obj->flags & MINUS))
		ft_fill(print->width, charset);
	if (((obj->flags & PLUS || obj->flags & SPACE) || obj->sign == '-') &&
							!(obj->flags & ZERO) && obj->conv != 'u')
		bonus += write(1, &obj->sign, 1);
	ft_fill(print->preci, '0');
	if (!(obj->preci == 0 && print->str[0] == '0'))
		write(1, print->str, print->size);
	if (obj->flags & MINUS)
		ft_fill(print->width, charset);
	return (print->width + print->preci + print->size + bonus);
}

static int		ft_manage_nbr(t_percent *obj, t_conv *conv,
												char *str, long long nbr)
{
	unsigned long long	nber;
	int					size;
	int					count;

	count = -1;
	nber = (nbr < 0 && ft_signed(conv, obj->conv)) ? -nbr : nbr;
	obj->sign = (nbr < 0 && ft_signed(conv, obj->conv)) ? '-' : '+';
	if (ft_signed(conv, obj->conv) || obj->conv == 'u')
		size = ft_str_nbr(obj, str, nber);
	else
	{
		while (++count < NB_BASES)
			if (obj->conv == conv->nbr.bases[count].conv)
				break ;
		size = ft_str_nbr_base(obj, str, nber, conv->nbr.bases[count].base);
	}
	return (size);
}

int				ft_print_number(t_percent *obj, t_conv *conv, long long nbr)
{
	int		size;
	t_print	print;

	size = 0;
	print.size = ft_manage_nbr(obj, conv, print.str, nbr);
	if (ft_signed(conv, obj->conv) || obj->conv == 'u')
		size = ft_print_nbr(obj, &print);
	else
		size = ft_print_nbr_bases(obj, &print);
	return (size);
}
