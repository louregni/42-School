/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:14:01 by louregni          #+#    #+#             */
/*   Updated: 2019/02/03 05:30:40 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_conversion.h"
#include "d_info.h"
#include "p_utils.h"

int		ft_signed(t_conv *conv, char c)
{
	int		count;

	count = -1;
	while (++count < NB_DECI)
		if (c == conv->nbr.deci[count])
			return (1);
	return (0);
}

int		ft_unsigned(t_conv *conv, char c)
{
	int		count;

	count = -1;
	if (c == 'u')
		return (1);
	while (++count < NB_BASES)
		if (c == conv->nbr.bases[count].conv)
			return (1);
	return (0);
}
