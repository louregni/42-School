/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:22:32 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/10 00:31:09 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (s1);
	ptr = s1;
	while (*ptr)
		ptr++;
	while (*s2 && n)
	{
		*ptr++ = *s2++;
		n--;
	}
	*ptr = '\0';
	return (s1);
}
