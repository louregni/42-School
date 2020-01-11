/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:56:58 by louregni          #+#    #+#             */
/*   Updated: 2018/11/20 16:07:51 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

static char		*conv_int(char *str, unsigned int nbr, size_t count)
{
	str[--count] = (nbr % 10) + '0';
	while (nbr /= 10)
	{
		if (str[--count] != '-')
			str[count] = (nbr % 10) + '0';
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	size_t			count;
	size_t			sign;

	sign = 0;
	count = 1;
	nbr = 0;
	if (n < 0 && count++)
		nbr -= n;
	else if (sign += 1)
		nbr = n;
	while (n /= 10)
		count++;
	if (!(str = ft_strnew(count)))
		return (NULL);
	if (sign == 0)
		str[0] = '-';
	return ((str = conv_int(str, nbr, count)));
}
