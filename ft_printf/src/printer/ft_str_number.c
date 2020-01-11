/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:33:57 by louregni          #+#    #+#             */
/*   Updated: 2019/02/03 05:24:56 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_flags.h"
#include "s_format.h"
#include "p_utils.h"

int		ft_str_nbr(t_percent *obj, char *str, unsigned long long nbr)
{
	int					count;
	unsigned long long	rest;

	if (obj->type == 0)
		nbr = (unsigned int)nbr;
	if (nbr == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (1);
	}
	count = 0;
	while (nbr)
	{
		if (obj->flags & QUOTE && !((count + 1) % 4) && count != 0)
			str[count++] = ',';
		rest = nbr % 10;
		str[count++] = (rest > 9) ? (rest - 10) + 'a' : rest + '0';
		nbr /= 10;
	}
	str[count] = '\0';
	ft_revert(str, count - 1);
	return (count);
}
