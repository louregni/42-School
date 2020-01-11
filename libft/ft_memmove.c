/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:23:23 by louregni          #+#    #+#             */
/*   Updated: 2018/11/19 16:53:11 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	count;

	if (dst == NULL && src == NULL)
		return (NULL);
	count = -1;
	if (dst <= src)
		while (++count < len)
			((unsigned char *)dst)[count] = ((unsigned char *)src)[count];
	else
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (dst);
}
