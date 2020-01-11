/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louregni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:19:18 by louregni          #+#    #+#             */
/*   Updated: 2018/11/27 15:28:28 by louregni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*add_lst(const int fd, t_file *lst)
{
	t_file	*new;

	if (!(new = malloc(sizeof(t_file))))
		return (NULL);
	new->fd = fd;
	new->line = NULL;
	new->next = lst;
	return (new);
}

int		one_newline(t_file *file, char **line)
{
	char *tmp;

	tmp = NULL;
	if (!(*line = ft_strdup("")))
		return (-1);
	if ((file->line[1] != 0) && !(tmp = ft_strdup(file->line + 1)))
		return (-1);
	free(file->line);
	file->line = tmp;
	tmp = NULL;
	return (1);
}

int		parse_line(t_file *file, char **line)
{
	char *tmp;

	tmp = NULL;
	if (file->line[0] == '\n')
		return (one_newline(file, line));
	if (!(*line = ft_strsep(file->line, '\n')))
		return (-1);
	if (ft_strlen(file->line) > (ft_strlen(*line) + 1))
	{
		if (!(tmp = ft_strdup(ft_strchr(file->line, '\n') + 1)))
			return (-1);
		free(file->line);
		file->line = tmp;
		tmp = NULL;
	}
	else
	{
		free(file->line);
		file->line = NULL;
	}
	return (1);
}

int		get_dis_line(t_file *file, char **line)
{
	ssize_t		r;
	char		*tmp;
	char		*tp;
	char		buff[BUFF_SIZE + 1];

	ft_memset(buff, 0, BUFF_SIZE + 1);
	if (file->line == NULL && (r = read(file->fd, buff, BUFF_SIZE)) <= 0)
		return (r);
	if (file->line == NULL && !(file->line = ft_strndup(buff, r)))
		return (-1);
	if (file->line != NULL && (ft_strchr(file->line, '\n') == NULL))
	{
		while (ft_strchr(file->line, '\n') == NULL &&
				(r = read(file->fd, buff, BUFF_SIZE)) > 0)
		{
			if (!(tmp = ft_strndup(buff, r)))
				return (-1);
			tp = file->line;
			if (!(file->line = ft_strjoin(file->line, tmp)))
				return (-1);
			free(tp);
			free(tmp);
		}
	}
	return (parse_line(file, line));
}

int		get_next_line(const int fd, char **line)
{
	t_file			*tmp;
	static t_file	*lst = NULL;

	if ((fd < 0 || line == NULL) || (lst == NULL && !(lst = add_lst(fd, lst))))
		return (-1);
	*line = NULL;
	tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (get_dis_line(tmp, line));
		tmp = tmp->next;
	}
	if (!(lst = add_lst(fd, lst)))
		return (-1);
	tmp = lst;
	return (get_dis_line(tmp, line));
}
