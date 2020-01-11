/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_get_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 20:48:33 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 13:25:27 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_GET_FORMAT_H
# define P_GET_FORMAT_H

int			ft_get_format(char **format, va_list current,
					t_percent *obj, t_conv *conv);
void		ft_check_dollar(char **format, t_percent *obj);
void		ft_check_flags(char **format, t_percent *obj);
void		ft_get_width(char **format, va_list current, t_percent *obj);
void		ft_get_precision(char **format, va_list current, t_percent *obj);
void		ft_get_type(char **format, t_percent *obj);
int			ft_get_conv(char **format, t_percent *obj, t_conv *conv);

#endif
