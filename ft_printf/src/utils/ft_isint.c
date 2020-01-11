/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 02:42:06 by louregni          #+#    #+#             */
/*   Updated: 2019/01/26 21:21:04 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_utils.h"

int		ft_isint(char *str)
{
	int			count;
	long long	value;

	count = 0;
	if (str[count] == '-' || str[count] == '+')
		++count;
	while (ft_isdigit(str[count]) == 1)
		++count;
	if (count > 11)
		return (0);
	value = ft_atoi_long(str);
	if (value > 2147483647 || value < -2147483648)
		return (0);
	return (1);
}
