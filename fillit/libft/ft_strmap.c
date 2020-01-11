/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:43:00 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/10 00:38:17 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*ptr;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(new = (char *)malloc((ft_strlen(s) + 1) * sizeof(*new))))
		return (NULL);
	ptr = new;
	while (*s)
	{
		*ptr = f(*s);
		ptr++;
		s++;
	}
	*ptr = '\0';
	return (new);
}
