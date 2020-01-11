/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:20:59 by louregni          #+#    #+#             */
/*   Updated: 2018/11/20 16:05:46 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchg(char *str, char target, char replace)
{
	size_t	count;

	if (str == NULL || replace == '\0' || target == '\0')
		return (NULL);
	if (target == replace)
		return (str);
	count = -1;
	while (str[++count])
		if (str[count] == target)
			str[count] = replace;
	return (str);
}
