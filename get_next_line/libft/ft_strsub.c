/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:15:03 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:56:37 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;
	char *save;

	if (!(str = ft_strnew(len)) || s == NULL)
		return (NULL);
	while (start--)
		s++;
	save = str;
	while (len--)
	{
		*str = *s;
		str++;
		s++;
	}
	return (save);
}
