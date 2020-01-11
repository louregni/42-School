/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 04:44:07 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:56:13 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char *ptr;
	char *save;
	char *end;

	if (s == NULL)
		return (0);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	ptr = (char *)s;
	while (*ptr)
		ptr++;
	while ((*ptr == ' ' || *ptr == '\t' || *ptr == '\n' ||
	*ptr == '\0') && ptr != s)
		ptr--;
	end = ptr;
	if (!(ptr = (char *)malloc((end - s + 2) * sizeof(char))))
		return (NULL);
	save = ptr;
	while (s <= end)
		*(ptr++) = *(s++);
	*ptr = '\0';
	return (save);
}
