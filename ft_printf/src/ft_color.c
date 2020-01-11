/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 07:25:29 by louregni          #+#    #+#             */
/*   Updated: 2019/02/08 09:38:01 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "p_utils.h"

int		ft_color(char **format, va_list current, va_list start)
{
	int size;

	size = 0;
	(void)current;
	(void)start;
	if (!ft_strncmp(&(*format)[0], "red}", 4) && (size = 4))
		write(1, "\033[31m", 5);
	else if (!ft_strncmp(&(*format)[0], "blue}", 5) && (size = 5))
		write(1, "\033[34m", 5);
	else if (!ft_strncmp(&(*format)[0], "eoc}", 4) && (size = 4))
		write(1, "\033[0m", 4);
	else
	{
		write(1, "{", 1);
		return (1);
	}
	*format += size;
	return (0);
}
