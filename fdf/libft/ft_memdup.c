/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:52:05 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/23 15:27:13 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memdup(void *src, size_t n)
{
	char	*dst;
	char	*ptr;

	if (src == NULL || n == 0)
		return (NULL);
	if (!(dst = malloc(n)))
		return (NULL);
	ptr = (char *)src;
	while (n--)
		dst[n] = ptr[n];
	return ((void *)dst);
}
