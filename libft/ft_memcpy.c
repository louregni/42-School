/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:12:23 by louregni          #+#    #+#             */
/*   Updated: 2018/11/19 11:26:14 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == NULL && src == NULL)
		return ((void *)NULL);
	while (n--)
		((char *)dst)[n] = ((char *)src)[n];
	return (dst);
}
