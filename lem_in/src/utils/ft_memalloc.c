/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:53:35 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:53:36 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*str;

	if (!(str = malloc(size)))
		return (NULL);
	while (size > 7)
	{
		size -= 8;
		*(unsigned long long *)(str + size) = 0;
	}
	while (size)
	{
		str[size] = 0;
		--size;
	}
	return ((void *)str);
}
