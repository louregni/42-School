/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:41:55 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/08 18:34:06 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	value;

	if (b == NULL)
		return (b);
	value = (unsigned char)c;
	while (len--)
		((unsigned char *)b)[len] = value;
	return (b);
}
