/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 04:55:04 by louregni          #+#    #+#             */
/*   Updated: 2019/02/03 05:13:52 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_conversion.h"
#include "d_info.h"
#include "p_chars.h"

static void	ft_init_char(t_char *charset)
{
	charset[0].conv = 'c';
	charset[0].ft_print = &ft_get_char;
	charset[1].conv = 's';
	charset[1].ft_print = &ft_get_string;
	charset[2].conv = 'p';
	charset[2].ft_print = &ft_get_pointer;
	charset[3].conv = '%';
	charset[3].ft_print = &ft_get_char;
}

static void	ft_init_number(t_number *nbr)
{
	nbr->deci[0] = 'i';
	nbr->deci[1] = 'd';
	nbr->bases[0].conv = 'o';
	nbr->bases[0].base = 8;
	nbr->bases[1].conv = 'x';
	nbr->bases[1].base = 16;
	nbr->bases[2].conv = 'X';
	nbr->bases[2].base = 16;
	nbr->bases[3].conv = 'b';
	nbr->bases[3].base = 2;
	nbr->bases[4].conv = 'u';
	nbr->bases[4].base = 10;
}

void		ft_init_convert(t_conv *conv)
{
	ft_init_number(&conv->nbr);
	ft_init_char(conv->charset);
}
