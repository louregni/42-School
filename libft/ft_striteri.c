/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:39:12 by louregni          #+#    #+#             */
/*   Updated: 2018/11/21 16:31:35 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	count;

	count = -1;
	if (s == NULL || f == NULL)
		return ;
	while (s[++count])
		f(count, &s[count]);
}
