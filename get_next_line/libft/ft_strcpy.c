/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:58:51 by louregni          #+#    #+#             */
/*   Updated: 2018/11/16 17:36:45 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	count;

	count = -1;
	while (src[++count])
		dst[count] = src[count];
	dst[count] = '\0';
	return (dst);
}
