/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:43:13 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/08 18:12:58 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	if (n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && (n - 1) > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}
