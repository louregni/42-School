/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:26:25 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/07 17:22:29 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	i = 0;
	while (i < n && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	if (i == n)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
