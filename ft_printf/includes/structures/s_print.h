/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:10:42 by louregni          #+#    #+#             */
/*   Updated: 2019/02/06 14:12:30 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PRINT_H
# define S_PRINT_H

typedef struct	s_print
{
	long long	width;
	long long	preci;
	int			size;
	char		str[65];
}				t_print;
#endif
