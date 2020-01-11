/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:05:45 by louregni          #+#    #+#             */
/*   Updated: 2018/11/10 11:23:39 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = (char *)s;
	while (*s)
		s++;
	if (*s == c && c == '\0')
		return ((char *)s);
	while ((char *)s-- >= start)
		if (*s == c)
			return ((char *)s);
	return (NULL);
}
