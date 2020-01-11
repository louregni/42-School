/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:14:06 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:28:52 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*save;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	save = str;
	while (*s)
	{
		*str = f(*s);
		str++;
		s++;
	}
	return (save);
}
