/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:08:04 by louregni          #+#    #+#             */
/*   Updated: 2018/11/30 15:29:12 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *str, size_t size)
{
	char	*new;
	size_t	count;

	count = 0;
	if (str == NULL || size == 0)
		return (NULL);
	if (!(new = malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (count < size && str[count])
	{
		new[count] = str[count];
		count++;
	}
	new[count] = '\0';
	return (new);
}
