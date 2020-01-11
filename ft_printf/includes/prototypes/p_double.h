/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_double.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:41:17 by louregni          #+#    #+#             */
/*   Updated: 2019/02/14 19:37:07 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_DOUBLE_H
# define P_DOUBLE_H
# include <stdarg.h>

long double		ft_get_double(t_percent *obj, va_list current, va_list start);
int				ft_decimal_double(t_percent *obj,
											t_double *ptr, long double nbr);
int				ft_integer_double(t_double *ptr, long double nbr);
int				ft_print_double(t_percent *obj,
								t_double *ptr, long double value);
#endif
