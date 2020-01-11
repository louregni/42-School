/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:18:38 by louregni          #+#    #+#             */
/*   Updated: 2018/11/20 17:03:51 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	count;

	count = -1;
	while (src[++count] && count < len)
		dst[count] = src[count];
	while (count < len)
		dst[count++] = '\0';
	return (dst);
}
