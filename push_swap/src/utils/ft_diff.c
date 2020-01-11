/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:42:28 by louregni          #+#    #+#             */
/*   Updated: 2019/07/13 18:42:30 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_diff(char *s1, char *s2, size_t n)
{
	while (n > 7)
	{
		n -= 8;
		if (*((long long *)(s1 + n)) ^ *((long long *)(s2 + n)))
			return (0);
	}
	if (n > 3)
	{
		n -= 4;
		if (*((int *)(s1 + n)) ^ *((int *)(s2 + n)))
			return (0);
	}
	if (n > 1)
	{
		n -= 2;
		if (*((short int*)(s1 + n)) ^ *((short int*)(s2 + n)))
			return (0);
	}
	if (n > 0)
	{
		n -= 1;
		if (*((char *)(s1 + n)) ^ *((char *)(s2 + n)))
			return (0);
	}
	return (1);
}
