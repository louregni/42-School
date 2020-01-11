/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:50:26 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:50:27 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		compare(void *dst, void *src, size_t n)
{
	while (n >= sizeof(unsigned long long))
	{
		n -= sizeof(unsigned long long);
		if (*(unsigned long long *)(dst + n) ^ *(unsigned long long *)(src + n))
			return (-1);
	}
	if (n >= sizeof(unsigned int))
	{
		n -= sizeof(unsigned int);
		if (*(unsigned int *)(dst + n) ^ *(unsigned int *)(src + n))
			return (-1);
	}
	while (n)
	{
		--n;
		if (*(unsigned char *)(dst + n) != *(unsigned char *)(src + n))
			return (-1);
	}
	return (0);
}
