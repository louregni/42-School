/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_chars.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 05:57:45 by louregni          #+#    #+#             */
/*   Updated: 2019/02/06 14:05:54 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_CHARS_H
# define P_CHARS_H
# include <stdarg.h>
# include "s_format.h"

int		ft_get_char(t_percent *obj, va_list current, va_list start);
int		ft_get_string(t_percent *obj, va_list current, va_list start);
int		ft_get_pointer(t_percent *obj, va_list current, va_list start);
#endif
