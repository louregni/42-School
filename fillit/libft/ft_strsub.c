/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:05:06 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/09 19:15:59 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	if (s == NULL)
		return (NULL);
	if (!(new = (char *)malloc((len + 1) * sizeof(*new))))
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = s[start + i];
	new[i] = '\0';
	return (new);
}
