/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:12:33 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/08 14:49:38 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (dst);
	i = 0;
	if (dst <= src)
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	else
		while (len)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	return (dst);
}
