/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:51:57 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:51:57 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strndup(const char *s1, size_t n)
{
	char *ptr;

	if (!(ptr = malloc(sizeof(char) * n)))
		return (0);
	while (n--)
		ptr[n] = s1[n];
	return (ptr);
}
