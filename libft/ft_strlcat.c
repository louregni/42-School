/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:31:59 by louregni          #+#    #+#             */
/*   Updated: 2018/11/20 17:03:24 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	count;

	count = 0;
	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	if (size < size_dst)
		return (size + size_src);
	while (dst[count])
		count++;
	while (*src && count + 1 < size)
		dst[count++] = *(src++);
	dst[count] = '\0';
	return (size_dst + size_src);
}
