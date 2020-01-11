/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:08:01 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 17:04:51 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	count;

	count = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (count < size)
		ptr[count++] = 0;
	return (ptr);
}
