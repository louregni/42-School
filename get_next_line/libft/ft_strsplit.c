/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 05:27:45 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:27:18 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*skip_char(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static char		**set_word(char **ptr, char const *s, char c, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len)
	{
		if (!(ptr[count++] = ft_strsep(s, c)))
			return ((char **)ft_ptrclr(ptr));
		while (*s != c && *s != '\0')
			s++;
		s = skip_char(s, c);
	}
	return (ptr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	char	*save;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = 0;
	save = skip_char(s, c);
	while (*s != '\0')
	{
		s = skip_char(s, c);
		if (*s != c && *s != '\0')
		{
			words++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	if (!(ptr = (char **)malloc((words + 1) * sizeof(char *))))
		return (NULL);
	ptr[words] = NULL;
	return (set_word(ptr, save, c, words));
}
