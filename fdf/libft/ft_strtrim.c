/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:16:37 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/14 12:22:27 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char		*new;
	const char	*start;
	char		*ptr;

	if (s == NULL)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	start = s;
	while (*s)
		s++;
	while (s != start && (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\0'))
		s--;
	if (!(new = (char *)malloc(((s - start) + 2) * sizeof(*new))))
		return (NULL);
	ptr = new;
	while (start <= s)
		*ptr++ = *start++;
	*ptr = '\0';
	return (new);
}
