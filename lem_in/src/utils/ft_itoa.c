/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:52:46 by louregni          #+#    #+#             */
/*   Updated: 2019/12/14 14:52:47 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	ft_itoa(unsigned int nbr, t_id *result)
{
	result->size = 0;
	result->ptr = result->name + 12;
	while (nbr && result->ptr != result->name)
	{
		--result->ptr;
		++result->size;
		*result->ptr = (nbr % 10) + '0';
		nbr /= 10;
	}
}
