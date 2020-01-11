/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:27:00 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/10 00:31:55 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	result;

	if (dst == NULL || src == NULL)
		return (-1);
	i = 0;
	while (i < size && dst[i])
		i++;
	result = ft_strlen(src);
	if (i >= size)
		return (result + size);
	result += i;
	while (*src && i < size - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (result);
}
