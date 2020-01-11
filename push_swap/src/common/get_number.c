/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:43 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:41:44 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static long long	ft_atoll(const char *str)
{
	long long		result;
	int				neg;

	neg = 1;
	if (!str)
		return (0);
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += ((*str - '0') * neg);
		++str;
		if (neg == -1 && result > 0)
			return (0);
		if (neg == 1 && result < 0)
			return (-1);
	}
	return (result);
}

int					get_number(char **str, int *result)
{
	char		nb_digit;
	long long	nbr;
	char		sign;

	if (!*str[0])
		return (2);
	sign = (*str[0] == '-' || *str[0] == '+') ? 1 : 0;
	nb_digit = 0;
	while ('0' <= (*(*str + nb_digit + sign))
		&& (*(*str + nb_digit + sign)) <= '9')
		if (++nb_digit > 10)
			return (0);
	if (!nb_digit)
		return (0);
	if ((nbr = ft_atoll(*str)) > 2147483647 || nbr < -2147483648)
		return (0);
	else
		*str += sign + nb_digit;
	*result = (int)nbr;
	while (**str == ' ')
		++*str;
	return (1);
}
