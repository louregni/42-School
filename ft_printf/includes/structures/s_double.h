/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_double.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 09:47:50 by louregni          #+#    #+#             */
/*   Updated: 2019/02/14 19:34:48 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DOUBLE_H
# define S_DOUBLE_H

typedef struct	s_double
{
	char	integer[16000];
	char	decimal[16000];
	char	*start_i;
}				t_double;
#endif
