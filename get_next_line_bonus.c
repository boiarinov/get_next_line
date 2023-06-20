/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:58:50 by aboiarin          #+#    #+#             */
/*   Updated: 2023/06/20 15:17:59 by aboiarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_act_line(const char *t)
{
	char	*line;
	int		i;

	i = 0;
	while (t[i] != '\0' && t[i] != '\n')
		i++;
	if (t[i] != '\0' && t[i] == '\n')
		i++;
	line = ft_memzero(i + 1, sizeof * line);
	if (!line)
		return (NULL);
	i = 0;
	while (t[i] != '\0' && t[i] != '\n')
	{
		line[i] = t[i];
		i++;
	}
	if (t[i] == '\n')
	{
		line[i] = t[i];
		i++;
	}
	return (line);
}

static char	*ft_next_line(const char *t)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	while (t && t[j])
		j++;
	i = 0;
	while (t[i] != '\0' && t[i] != '\n')
		i++;
	if (t[i] != '\0' && t[i] == '\n')
		i++;
	line = ft_memzero((j - i) + 1, sizeof * line);
	if (!line)
		return (NULL);
	j = 0;
	while (t[i + j])
	{
		line[j] = t[i + j];
		j++;
	}
	return (line);
}

static void	ft_read_line(char **storage, int fd, char **t)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_str(&buf, storage, t);
			return ;
		}
		buf[r] = '\0';
		*t = ft_strdup(*storage);
		ft_free_str(storage, 0, 0);
		*storage = ft_join(*t, buf);
		ft_free_str(t, 0, 0);
		if (ft_newline(*storage))
			break ;
	}
	ft_free_str(&buf, 0, 0);
}

static char	*ft_get_lines(char **storage, char **t)
{
	char	*line;

	*t = ft_strdup(*storage);
	ft_free_str(storage, 0, 0);
	*storage = ft_next_line(*t);
	line = ft_act_line(*t);
	ft_free_str(t, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	char		*t;
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	t = NULL;
	ft_read_line(&storage[fd], fd, &t);
	if (storage[fd] != NULL && *storage[fd] != '\0')
		line = ft_get_lines(&storage[fd], &t);
	if (!line || *line == '\0')
	{
		ft_free_str(&storage[fd], &t, &line);
		return (NULL);
	}
	return (line);
}
