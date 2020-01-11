/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:48:46 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/12 14:50:12 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_sqrt(int nb)
{
	int	max;
	int	i;

	if (nb <= 0)
		return (-1);
	max = nb / 3;
	if (nb == 4)
		return (2);
	i = 0;
	while (++i <= max)
		if (i * i == nb)
			return (i);
	return (0);
}
