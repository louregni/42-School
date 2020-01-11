/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 20:50:14 by louregni          #+#    #+#             */
/*   Updated: 2019/02/15 15:21:44 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_UTILS_H
# define P_UTILS_H
# include <string.h>
# include <stdarg.h>
# include "s_conversion.h"
# include "s_format.h"

size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
long long		ft_atoi_long(const char *str);
int				ft_isint(char *str);
void			ft_revert(char *str, int count);
unsigned char	ft_get_base(char c, t_conv *conv);
void			ft_set_va(t_percent *obj, va_list start);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
