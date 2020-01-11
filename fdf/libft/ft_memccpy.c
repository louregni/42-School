/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:03:02 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/15 12:01:32 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	value;
	size_t			i;

	if (dst == NULL || src == NULL)
		return (NULL);
	i = 0;
	value = (unsigned char)c;
	while (i < n && ((unsigned char *)src)[i] != value)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	if (i == n)
		return (NULL);
	((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	i++;
	return (&dst[i]);
}
