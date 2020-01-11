/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 07:50:31 by louregni          #+#    #+#             */
/*   Updated: 2018/11/20 16:57:32 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*(unsigned char *)dst = (unsigned char)c;
			return (++dst);
		}
		*(char *)(dst++) = *(char *)(src++);
	}
	return (NULL);
}
