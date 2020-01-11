/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:29:12 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/15 18:37:18 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_part_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char		**ft_fill_tab(char const *s, char c, char **tab, int i)
{
	size_t	j;
	size_t	len;

	while (*s)
	{
		while (*s && *s == c)
			s++;
		if ((j = 0) == 0 && *s)
		{
			len = ft_part_len(s, c);
			if (!(tab[i] = (char *)malloc((len + 1) * sizeof(*tab[i]))))
			{
				while (--i >= 0)
					free(tab[i]);
				free(tab);
				return (NULL);
			}
			while (*s && *s != c)
				tab[i][j++] = *s++;
			tab[i++][j] = '\0';
		}
	}
	tab[i] = NULL;
	return (tab);
}

static char		**ft_creat_tab(char const *s, char c)
{
	int		count;
	char	**tab;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	if (!(tab = (char **)malloc((count + 1) * sizeof(*tab))))
		return (NULL);
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**tab;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(tab = ft_creat_tab(s, c)))
		return (NULL);
	tab = ft_fill_tab(s, c, tab, 0);
	return (tab);
}
