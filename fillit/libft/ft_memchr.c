/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:19:29 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/09 21:04:29 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	value;
	size_t			i;

	if (s == NULL)
		return (NULL);
	value = (unsigned char)c;
	i = 0;
	while (i < n && ((unsigned char *)s)[i] != value)
		i++;
	if (i == n)
		return (NULL);
	return (&((void *)s)[i]);
}
