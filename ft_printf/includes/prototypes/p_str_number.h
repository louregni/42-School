/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_str_number.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:47:17 by louregni          #+#    #+#             */
/*   Updated: 2019/02/06 14:08:16 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_STR_NUMBER_H
# define P_STR_NUMBER_H

int		ft_str_nbr(t_percent *obj, char *str, unsigned long long nbr);
int		ft_str_nbr_base(t_percent *obj, char *str, unsigned long long nbr,
			unsigned char base);
#endif
