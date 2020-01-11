/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:03:37 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/09 21:08:38 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	if (!(dup = (char*)malloc((ft_strlen(s1) + 1) * sizeof(*dup))))
		return (NULL);
	ptr = dup;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (dup);
}
