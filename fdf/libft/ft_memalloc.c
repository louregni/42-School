/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:35:55 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/10 00:37:09 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	i;

	if (!(ptr = (char *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		ptr[i++] = 0;
	return ((void *)ptr);
}
