/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:30:12 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/12 15:24:48 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_pow(int base, int exponent)
{
	int	result;

	if (exponent < 0)
		return (0);
	if (exponent == 0)
		return (1);
	result = base;
	while (--exponent)
		result *= base;
	return (result);
}
