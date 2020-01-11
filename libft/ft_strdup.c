/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:12:54 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:58:47 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*save;

	if ((!(str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char)))) || !s1)
		return (NULL);
	save = str;
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	*str = '\0';
	return (save);
}
