/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <louregni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:42:48 by louregni          #+#    #+#             */
/*   Updated: 2019/07/18 01:08:57 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <stddef.h>
# define STACK_A 1
# define STACK_B 2

typedef struct	s_list
{
	int				value;
	unsigned int	index;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct	s_stack
{
	t_list			*start;
	unsigned int	size;
}				t_stack;

typedef struct	s_container
{
	t_stack			a;
	t_stack			b;
	unsigned int	size;
	unsigned int	pivot;
	unsigned int	floor;
}				t_container;

typedef struct	s_soluce
{
	unsigned long long	order;
	char				*soluce;
}				t_soluce;

/*
** About chained list
*/

void			del(t_list *start);
t_list			*pop_list(t_list **start);
void			push_list(t_list **start, t_list *elem);
void			push_action(t_list **start, t_list *elem);
int				create_list(t_container *box, int ac, char **av);

/*
** Actions
*/

void			swaping(t_stack *s);
void			rotate(t_container *box, char index);
void			revrotate(t_container *box, char index);
void			push(t_container *box, char index);
void			swap(t_container *box, char index);

void			quicksort(int *tab, int first, int last);
int				parse(t_container *box, int ac, char **av);
int				is_sort(t_list *start);
int				*get_tab(t_container *box);

/*
** Utils
*/

int				get_number(char **str, int *result);
int				ft_diff(char *s1, char *s2, size_t n);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *src);

/*
** Sortings
*/

unsigned int	sort_recurse(t_container *box,
	unsigned int high, unsigned int low, int end);
unsigned int	opti_easy(t_container *box);
unsigned int	split_a(t_container *box, unsigned int high, unsigned int low);

#endif
