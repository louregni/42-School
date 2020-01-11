/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:20:43 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/10 00:30:17 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ptr;

	if (dst == NULL || src == NULL)
		return (dst);
	ptr = dst;
	while (len && *src)
	{
		*ptr++ = *src++;
		len--;
	}
	if (len == 0)
		return (dst);
	while (len--)
		*ptr++ = '\0';
	return (dst);
}
