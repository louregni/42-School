/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:29:21 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:39:21 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsep(const char *str, const char sep)
{
	size_t	count;
	char	*ptr;

	if (!str)
		return (NULL);
	count = 0;
	while (str[count] != '\0' && str[count] != sep)
		count++;
	if (!(ptr = (char *)malloc((count + 1) * sizeof(char))))
		return (NULL);
	ptr[count] = '\0';
	while (--count > 0)
		ptr[count] = str[count];
	ptr[0] = str[0];
	return (ptr);
}
