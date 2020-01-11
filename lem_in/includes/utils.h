/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 04:37:50 by louregni          #+#    #+#             */
/*   Updated: 2019/12/16 04:37:52 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>

void	ft_bzero(void *mem, size_t size);
void	ft_itoa(unsigned int nbr, t_id *result);
void	*ft_memalloc(size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_memcpy(void *dst, void *src, size_t n);
int		ft_strcmp(char *src, char *dst, unsigned int size);
char	*ft_strndup(const char *s1, size_t n);
int		compare(void *dst, void *src, size_t n);
void	ft_itoa(unsigned int nbr, t_id *result);

#endif
