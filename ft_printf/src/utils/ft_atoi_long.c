/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 02:52:25 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 13:37:19 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_utils.h"

long long	ft_atoi_long(const char *str)
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
