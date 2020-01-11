/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 05:11:39 by louregni          #+#    #+#             */
/*   Updated: 2019/02/01 05:19:29 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_info.h"
#include "s_conversion.h"

unsigned char	ft_get_base(char c, t_conv *conv)
{
	int		count;

	count = -1;
	while (++count < NB_BASES)
		if (c == conv->nbr.bases[count].conv)
			return (conv->nbr.bases[count].base);
	return (0);
}
