/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:35:14 by louregni          #+#    #+#             */
/*   Updated: 2018/11/20 13:45:40 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memdup(void *ptr, size_t size)
{
	unsigned char	*cpy;

	if (ptr == NULL || size == 0)
		return (NULL);
	if (!(cpy = (unsigned char *)malloc(size)))
		return (NULL);
	while (size--)
		cpy[size] = ((unsigned char *)ptr)[size];
	return (cpy);
}
