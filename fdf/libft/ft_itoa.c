/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:12:20 by ckillian          #+#    #+#             */
/*   Updated: 2018/12/04 16:08:38 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	static	size_t	len = 0;
	char			*result;
	int				r;
	size_t			i;

	len++;
	if (n / 10 != 0)
	{
		if (!(result = ft_itoa(n / 10)))
			return (NULL);
	}
	else
	{
		if (!(result = ft_strnew((n < 0) ? (len + 1) : (len))))
			return (NULL);
		len = 0;
		if (n < 0)
			result[0] = '-';
	}
	i = 0;
	r = (n % 10) < 0 ? ((n % 10) * -1) : (n % 10);
	while (result[i] != '\0')
		i++;
	result[i] = r + '0';
	return (result);
}
