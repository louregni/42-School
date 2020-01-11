/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:08:34 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:53:32 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_ptrclr(char **ptr)
{
	size_t	count;

	if (!(ptr))
		return ((void *)NULL);
	count = 0;
	while (ptr[count] != NULL)
		free(ptr[count++]);
	free(ptr);
	return (NULL);
}
