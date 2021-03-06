/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:08:04 by louregni          #+#    #+#             */
/*   Updated: 2018/11/25 17:14:36 by louregni         ###   ########.fr       */
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
	new[size] = '\0';
	while (count < size && str[count])
	{
		new[count] = str[count];
		count++;
	}
	return (new);
}
