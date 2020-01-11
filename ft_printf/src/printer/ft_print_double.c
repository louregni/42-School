/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 09:41:25 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 15:35:05 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "d_info.h"
#include "d_flags.h"
#include "s_double.h"
#include "s_format.h"
#include "p_double.h"
#include "p_fill.h"
#include "p_utils.h"

static void		ft_init_double(t_double *ptr)
{
	ptr->integer[15999] = '\0';
	ptr->start_i = &(ptr->integer[15998]);
}

static int		ft_printer(t_percent *obj, t_double *ptr, int dec, int inte)
{
	char bonus;
	char charset;

	bonus = 0;
	obj->sign = (obj->flags & SPACE && obj->sign == '+') ? ' ' : obj->sign;
	charset = (obj->flags & ZERO) ? '0' : ' ';
	if (obj->flags & ZERO && (((obj->flags & PLUS || obj->flags & SPACE) &&
					obj->sign != '-') || obj->sign == '-'))
		bonus += write(1, &obj->sign, 1);
	if (!(obj->flags & MINUS))
		ft_fill(obj->width, charset);
	if (!(obj->flags & ZERO) && (((obj->flags & PLUS || obj->flags & SPACE) &&
									obj->sign != '-') || obj->sign == '-'))
		bonus += write(1, &obj->sign, 1);
	write(1, ptr->start_i, inte);
	if (obj->preci > 0 || obj->flags & DIEZ)
		bonus += write(1, ".", 1);
	if (obj->preci > 0)
		write(1, ptr->decimal, dec);
	ft_fill(obj->preci - dec, '0');
	if (obj->flags & MINUS)
		ft_fill(obj->width, charset);
	return (inte + dec + bonus);
}

static void		ft_patch(t_percent *obj, int inte)
{
	if (obj->flags & SPACE && obj->flags & PLUS)
		obj->flags ^= SPACE;
	if (obj->flags & ZERO && obj->flags & MINUS)
		obj->flags ^= ZERO;
	obj->width -= obj->preci;
	obj->width -= inte;
	obj->width -= (obj->flags & PLUS || obj->flags & SPACE ||
											obj->sign == '-') ? 1 : 0;
	obj->width -= (!(obj->flags & DIEZ) && obj->preci == 0) ? 0 : 1;
	obj->width = (obj->width < 0) ? 0 : obj->width;
}

static int		ft_check(long double nbr)
{
	uint64_t		mantissa;
	uint64_t		*tmp;
	unsigned int	exponent;
	char			sign;

	tmp = (uint64_t *)&nbr;
	mantissa = (tmp[0]);
	exponent = ((tmp[1] & 0x7FFF));
	sign = (((tmp[1]) << 48) >> 63);
	if (exponent == 0x7FFF)
	{
		if (sign == 1 && (mantissa == 0 || mantissa == 0x8000000000000000))
			return (write(1, "-inf", 4));
		else if (mantissa == 0 || mantissa == 0x8000000000000000)
			return (write(1, "inf", 3));
		else
			return (write(1, "nan", 3));
	}
	else if (mantissa == 0 && exponent == 0 && sign == 1)
		return (write(1, "-0", 2));
	return (0);
}

int				ft_print_double(t_percent *obj,
									t_double *ptr, long double value)
{
	int		dec;
	int		inte;
	int		error;
	int		size;

	if ((error = ft_check(value)) != 0)
		return (error);
	obj->sign = (value < 0) ? '-' : '+';
	value = (value < 0) ? -value : value;
	ft_init_double(ptr);
	inte = ft_integer_double(ptr, value);
	dec = ft_decimal_double(obj, ptr, value);
	ft_patch(obj, inte);
	size = ft_printer(obj, ptr, dec, inte);
	return (size);
}
