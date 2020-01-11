/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:44:00 by louregni          #+#    #+#             */
/*   Updated: 2018/11/20 20:03:58 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;
	size_t	count;

	size = ft_strlen(needle);
	count = 0;
	if (size == 0)
		return ((char *)haystack);
	if (len == 0)
		return ((char *)NULL);
	if (size > ft_strlen(haystack))
		return ((char *)NULL);
	while ((count + size) <= len)
	{
		if (!(ft_memcmp(haystack, needle, size)))
			return ((char *)haystack);
		haystack++;
		count++;
	}
	return ((char *)NULL);
}
