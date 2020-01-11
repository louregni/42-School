/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:16:28 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/10 00:29:38 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	char	*ptr;

	ptr = dst;
	if (src == NULL || dst == NULL)
		return (dst);
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dst);
}
