/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_number_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 21:28:45 by louregni          #+#    #+#             */
/*   Updated: 2019/02/03 05:29:55 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_format.h"
#include "d_flags.h"
#include "p_utils.h"

int		ft_str_nbr_base(t_percent *obj, char *str, unsigned long long nbr,
												unsigned char base)
{
	int					count;
	unsigned long long	rest;
	char				c;

	c = (obj->conv == 'X') ? 'A' : 'a';
	if (nbr == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (1);
	}
	count = 0;
	while (nbr)
	{
		rest = nbr % base;
		str[count++] = (rest > 9) ? (rest - 10) + c : rest + '0';
		nbr /= base;
	}
	str[count] = '\0';
	ft_revert(str, count - 1);
	return (count);
}
