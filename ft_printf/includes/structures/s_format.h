/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 20:51:05 by louregni          #+#    #+#             */
/*   Updated: 2019/02/06 14:06:47 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FORMAT_H
# define S_FORMAT_H

typedef struct	s_percent
{
	int		arg_n;
	char	flags;
	int		width;
	int		preci;
	char	type;
	char	conv;
	char	sign;
}				t_percent;
#endif
