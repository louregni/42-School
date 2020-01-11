/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_modifier.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 20:51:18 by louregni          #+#    #+#             */
/*   Updated: 2019/01/26 21:03:21 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MODIFIER_H
# define S_MODIFIER_H

typedef struct	s_modifier
{
	char	charset;
	int		(*ft_parsing)();
}				t_modifier;

#endif
