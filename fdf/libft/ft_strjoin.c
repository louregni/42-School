/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:11:29 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/22 17:08:44 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*ptr;
	size_t	i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) *
								sizeof(char))))
		return (NULL);
	ptr = new;
	i = 0;
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && s2[i])
	{
		ptr[i] = s2[i];
		i++;
	}
	ptr[i] = '\0';
	return (new);
}
