/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 06:11:36 by louregni          #+#    #+#             */
/*   Updated: 2019/02/01 06:16:37 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_info.h"
#include "s_conversion.h"

int		ft_ischar(t_conv *conv, char c)
{
	int count;

	count = -1;
	while (++count < NB_CHAR)
		if (c == conv->charset[count].conv)
			return (1);
	return (0);
}
