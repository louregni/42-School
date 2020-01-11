/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_modifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:33:44 by louregni          #+#    #+#             */
/*   Updated: 2019/02/08 07:42:54 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "s_modifier.h"
#include "p_percent.h"
#include "p_color.h"

void		ft_init_modifier(t_modifier *modifiers)
{
	modifiers[0].charset = '%';
	modifiers[0].ft_parsing = &ft_percent;
	modifiers[1].charset = '{';
	modifiers[1].ft_parsing = &ft_color;
}
