/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:16:55 by louregni          #+#    #+#             */
/*   Updated: 2018/11/20 13:27:43 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	--s;
	while (*(++s))
		if ((char)c == *s)
			return ((char *)s);
	if (*s == (char)c && (char)c == '\0')
		return ((char *)s);
	return (NULL);
}
