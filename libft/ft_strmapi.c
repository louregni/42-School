/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:03:35 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:57:55 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	count;

	count = -1;
	if (s == NULL || !(str = ft_strnew(ft_strlen(s))) || f == NULL)
		return (NULL);
	while (s[++count])
		str[count] = f(count, s[count]);
	return (str);
}
