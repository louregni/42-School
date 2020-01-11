/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 02:12:38 by ckillian          #+#    #+#             */
/*   Updated: 2018/11/23 16:24:04 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 500

# include <string.h>

typedef struct	s_line
{
	int		fd;
	ssize_t	len;
	char	*buf;
}				t_line;

int				get_next_line(const int fd, char **line);

#endif
