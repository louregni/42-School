/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:21:36 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/22 17:07:07 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memjoin(void *ptr1, void *ptr2, size_t size1, size_t size2)
{
	char	*new;
	size_t	i;

	if (ptr1 == NULL && ptr2 == NULL)
		return (NULL);
	if (!(new = malloc(size1 + size2)))
		return (NULL);
	i = -1;
	while (ptr1 && ((char *)ptr1)[++i])
		new[i] = ((char *)ptr1)[i];
	while (ptr2 && ((char *)ptr2)[++i])
		new[i] = ((char *)ptr1)[i];
	return ((void *)new);
}
