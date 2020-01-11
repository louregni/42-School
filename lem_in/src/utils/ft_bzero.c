/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:50:17 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:50:17 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *mem, size_t size)
{
	while (size > 7)
	{
		size -= 8;
		*(unsigned long long *)(mem + size) = 0;
	}
	while (size)
	{
		--size;
		*(unsigned char *)(mem + size) = 0;
	}
}
