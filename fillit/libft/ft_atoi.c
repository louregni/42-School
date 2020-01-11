/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:12:20 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/14 15:45:55 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long		result;
	int				neg;

	neg = 1;
	if (str == NULL)
		return (0);
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
	{
		result *= 10;
		result += ((*str - '0') * neg);
		str++;
		if (neg == -1 && result > 0)
			return (0);
		if (neg == 1 && result < 0)
			return (-1);
	}
	return (result);
}
