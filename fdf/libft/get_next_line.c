/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckillian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:30:08 by ckillian          #+#    #+#             */
/*   Updated: 2019/01/23 17:42:10 by ckillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

t_line	*ft_check_list(t_list **lst, const int fd)
{
	t_line	*line;
	t_list	*ptr;

	ptr = *lst;
	while (ptr)
	{
		line = (t_line *)ptr->content;
		if (line->fd == fd)
			return ((t_line *)(ptr->content));
		ptr = ptr->next;
	}
	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	line->fd = fd;
	line->buf = NULL;
	line->len = 0;
	if (!(ptr = ft_lstnew(line, sizeof(t_line))))
	{
		free(line);
		return (NULL);
	}
	free(line);
	ft_lstadd(lst, ptr);
	return (ptr->content);
}

int		ft_last_line(t_line *l, char **line)
{
	char	*new_line;

	if (!(new_line = ft_memdup(l->buf, l->len)))
		return (-1);
	*line = new_line;
	free(l->buf);
	l->buf = NULL;
	l->len = 0;
	return (1);
}

int		ft_set_newline(char *ptr, t_line *l, char **line, int end)
{
	char	*new_line;
	char	*ptr2;

	if (end)
		return (ft_last_line(l, line));
	if (!(new_line = ft_memdup(l->buf, (ptr - l->buf) + 1)))
		return (-1);
	new_line[(ptr - l->buf)] = '\0';
	if ((ptr - l->buf) >= l->len - 2 && (l->len = 0 == 0))
	{
		free(l->buf);
		l->buf = NULL;
		*line = new_line;
		return (1);
	}
	if (!(ptr2 = ft_memdup((ptr + 1), (l->len - (ptr - l->buf) - 1))))
	{
		free(new_line);
		return (-1);
	}
	*line = new_line;
	free(l->buf);
	l->len = (l->len - (ptr - l->buf) - 1);
	l->buf = ptr2;
	return (1);
}

int		ft_check_buf(t_line *l, char **line, ssize_t len)
{
	char	*ptr;
	char	*buf;
	char	*new_line;

	while (1)
	{
		if ((ptr = ft_memchr(l->buf, '\n', l->len)) || len == 0)
			return (ft_set_newline(ptr, l, line, (len == 0) ? 1 : 0));
		if (!(new_line = malloc(l->len + BUFF_SIZE)))
			return (-1);
		new_line = ft_memcpy(new_line, l->buf, l->len);
		free(l->buf);
		buf = malloc(BUFF_SIZE);
		if (buf == NULL || ((len = read(l->fd, buf, BUFF_SIZE)) == -1))
		{
			l->buf = new_line;
			free(buf);
			return (-1);
		}
		ft_memcpy((new_line + (l->len - 1)), buf, len);
		l->len += len;
		l->buf = new_line;
		l->buf[l->len - 1] = '\0';
		free(buf);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_line			*l;
	char			*ptr;

	if (line == NULL || !(l = ft_check_list(&lst, fd)))
		return (-1);
	if (l->buf == NULL)
	{
		if (!(ptr = (char *)malloc(BUFF_SIZE + 1)))
			return (-1);
		if ((l->len = read(l->fd, ptr, BUFF_SIZE)) <= 0)
		{
			free(ptr);
			return (l->len);
		}
		ptr[l->len] = '\0';
		if (!(l->buf = ft_memdup(ptr, ++(l->len))))
		{
			l->buf = ptr;
			return (-1);
		}
		free(ptr);
	}
	return (ft_check_buf(l, line, 1));
}
