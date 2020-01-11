/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:34:34 by louregni          #+#    #+#             */
/*   Updated: 2019/01/30 17:56:41 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "d_flags.h"
#include "s_format.h"

void	ft_fill(long long dif, char fill)
{
	int		count;
	char	buf[4096];

	count = -1;
	if (dif <= 0)
		return ;
	if (dif > 4095)
	{
		while (++count < 4096)
			buf[count] = fill;
	}
	while (dif > 4095)
	{
		write(1, buf, 4096);
		dif -= 4096;
	}
	while (dif-- > 0)
		write(1, &fill, 1);
}
