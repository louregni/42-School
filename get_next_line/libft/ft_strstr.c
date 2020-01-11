/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:24:20 by louregni          #+#    #+#             */
/*   Updated: 2018/11/14 16:59:09 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*save;
	char	*save1;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		save = (char *)haystack;
		save1 = (char *)needle;
		while (*haystack == *needle && *haystack != '\0')
		{
			haystack++;
			needle++;
		}
		if (*needle == '\0')
			return (save);
		haystack = ++save;
		needle = save1;
	}
	return ((char *)NULL);
}
