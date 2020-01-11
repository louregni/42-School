/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:52:37 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:52:38 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_memcpy(void *dst, void *src, size_t n)
{
	while (n > 7)
	{
		*(unsigned long long *)dst = *(unsigned long long *)src;
		dst += 8;
		src += 8;
		n -= 8;
	}
	if (n > 3)
	{
		*(unsigned int *)dst = *(unsigned int *)src;
		dst += 4;
		src += 4;
		n -= 4;
	}
	while (n)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		++dst;
		++src;
		--n;
	}
}
