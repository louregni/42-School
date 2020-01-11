/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:53:44 by louregni          #+#    #+#             */
/*   Updated: 2018/12/07 17:50:03 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define SQUARE	0b1000000000000000
# define LINE	0b0100000000000000
# define TEA 	0b0010000000000000
# define SNAKE 	0b0001000000000000
# define LET 	0b0000100000000000
# define FACE_1 0b0000000010000000
# define FACE_2 0b0000000001000000
# define FACE_3 0b0000000000100000
# define FACE_4 0b0000000000010000
# define FACE_5 0b0000000000001000
# define FACE_6 0b0000000000000100
# define FACE_7 0b0000000000000010
# define FACE_8 0b0000000000000001

typedef struct	s_sqr
{
	char	*sqr;
	char	sqr_size;
	int		i;
}				t_sqr;

typedef int		t_f(t_sqr *square, char ltr, int (*f)(char *, char));
int				ft_error(char *buf, unsigned short *tetro);
void			ft_print(t_sqr *square);
t_sqr			*ft_backtrack(unsigned short *tetr, t_sqr *square, char ltr);
t_sqr			*ft_fillit(unsigned short *tab, char nbt);

#endif
