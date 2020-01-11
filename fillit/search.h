/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 18:29:08 by louregni          #+#    #+#             */
/*   Updated: 2018/12/06 15:59:15 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_H
# define SEARCH_H

t_f	*ft_face_sqr(unsigned short tetro);
int	ft_face_sqr_f1(t_sqr *square, char ltr, int (*f)(char *));

t_f	*ft_face_line(unsigned short tetro);
int	ft_face_line_f1(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_line_f2(t_sqr *square, char ltr, int (*f)(char *, char));

t_f	*ft_face_t(unsigned short tetro);
int	ft_face_t_f1(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_t_f2(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_t_f3(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_t_f4(t_sqr *square, char ltr, int (*f)(char *, char));

t_f	*ft_face_s(unsigned short tetro);
int	ft_face_s_f1(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_s_f2(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_s_f3(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_s_f4(t_sqr *square, char ltr, int (*f)(char *, char));

t_f	*ft_face_l(unsigned short tetro);
int	ft_face_l_f1(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_l_f2(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_l_f3(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_l_f4(t_sqr *square, char ltr, int (*f)(char *, char));

t_f	*ft_face_l2(unsigned short tetro);
int	ft_face_l2_f1(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_l2_f2(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_l2_f3(t_sqr *square, char ltr, int (*f)(char *, char));
int	ft_face_l2_f4(t_sqr *square, char ltr, int (*f)(char *, char));

t_f	*ft_isplaceable(t_sqr *square, unsigned short tetro);
int	ft_search(char *c, char ltr);
int	ft_write_tetro(char *c, char ltr);
int	ft_del_tetro(char *c, char ltr);

#endif
