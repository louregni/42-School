/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:20:56 by louregni          #+#    #+#             */
/*   Updated: 2018/11/09 19:35:06 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *save;

	if (s1 == NULL || s2 == NULL || !(str = malloc((1 + ft_strlen(s1)
	+ ft_strlen(s2)) * sizeof(char))))
		return (NULL);
	save = str;
	while (*s1)
		*(str++) = *(s1++);
	while (*s2)
		*(str++) = *(s2++);
	*str = '\0';
	return (save);
}
