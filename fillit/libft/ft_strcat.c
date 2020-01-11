/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:16:27 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/10 00:30:47 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ptr;

	if (s2 == NULL || s1 == NULL)
		return (s1);
	ptr = s1;
	while (*ptr)
		ptr++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (s1);
}
