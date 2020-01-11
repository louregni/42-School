/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 09:41:18 by louregni          #+#    #+#             */
/*   Updated: 2019/02/14 17:54:20 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_flags.h"
#include "s_format.h"
#include "s_double.h"

static long double		ft_ldbl_truncate(long double nbr)
{
	long double	tmp;

	tmp = nbr;
	if (nbr == 1.0)
		return (nbr);
	nbr = ((nbr) + 0x1p64) - 0x1p64;
	if (nbr < 0.0)
		nbr = nbr < tmp ? nbr + 1.0 : nbr;
	else if (nbr > 0.0)
		nbr = nbr > tmp ? nbr - 1.0 : nbr;
	return (nbr);
}

static long double		ft_get_preci(t_percent *obj, long double nbr)
{
	int			count;
	long double	div;

	count = 0;
	div = 10;
	while (count < obj->preci)
	{
		nbr *= 10.;
		nbr = nbr - ft_ldbl_truncate(nbr);
		++count;
		div *= 10.;
	}
	nbr *= 10.;
	if (nbr > 4.0)
		return (nbr / div);
	return (0.0);
}

int						ft_integer_double(t_double *ptr, long double nbr)
{
	long double		tmp;
	char			*save;
	char			c;

	nbr = ft_ldbl_truncate(nbr);
	save = ptr->start_i;
	if (nbr == 0.0)
	{
		*(ptr->start_i) = '0';
		return (1);
	}
	while ((int)nbr)
	{
		tmp = (nbr - (ft_ldbl_truncate(nbr / 10.) * 10.));
		c = (int)tmp;
		nbr /= 10.;
		nbr = ft_ldbl_truncate(nbr);
		*(ptr->start_i--) = c + '0';
	}
	ptr->start_i += 1;
	return ((save - ptr->start_i) + 1);
}

int						ft_decimal_double(t_percent *obj,
										t_double *ptr, long double nbr)
{
	int			count;
	char		c;

	count = 0;
	if (obj->preci == 0)
		return (0);
	else if (obj->preci == -1)
		obj->preci = 6;
	nbr = nbr - ft_ldbl_truncate(nbr);
	nbr += ft_get_preci(obj, nbr);
	while (count < obj->preci && count < 15998)
	{
		nbr *= 10.;
		c = (int)nbr + '0';
		ptr->decimal[count] = (c > '9' || c < '0') ? '0' : c;
		nbr = nbr - ft_ldbl_truncate(nbr);
		++count;
	}
	ptr->decimal[count] = '\0';
	return (count);
}
