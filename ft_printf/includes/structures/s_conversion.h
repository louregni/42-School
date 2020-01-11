/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conversion.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 20:50:54 by louregni          #+#    #+#             */
/*   Updated: 2019/02/06 14:12:50 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CONVERSION_H
# define S_CONVERSION_H
# include "d_info.h"

typedef struct	s_unsigned
{
	char			conv;
	unsigned char	base;
}				t_unsigned;

typedef struct	s_number
{
	t_unsigned		bases[NB_BASES];
	char			deci[NB_DECI];
}				t_number;

typedef struct	s_char
{
	char			conv;
	int				(*ft_print)();
}				t_char;

typedef struct	s_conv
{
	t_number		nbr;
	t_char			charset[NB_CHAR];
}				t_conv;
#endif
