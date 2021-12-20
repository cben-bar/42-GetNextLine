/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:18:58 by cben-bar          #+#    #+#             */
/*   Updated: 2021/12/20 23:12:17 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_where_nl(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (i - 1);
	return (FALSE);
}

static char	*ft_super_join(char *s1, char *s2)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((s1 && s1[++i]) || (s2 && s2[++j]))
		;
	buff = malloc(sizeof(char) * (i + j + 1));
	if (!buff)
		return (0);
	i = 0;
	while (s1 && s1[i] && i++ >= 0)
		buff[i - 1] = s1[i - 1];
	j = 0;
	while (s2 && s2[j] && j++ >= 0)
		buff[i + j - 1] = s2[j - 1];
	buff[i + j] = '\0';
	if (s1)
		free(s1);
	return (buff);
}

static int	ft_read(int fd, char **backl, char **line, int eof)
{
	char	buff[BUFFER_SIZE + 1];

	*line = ft_super_join(*line, *backl);
	while (ft_where_nl(*line, '\n') == FALSE)
	{
		eof = read(fd, buff, BUFFER_SIZE);
		if (eof <= 0)
		{
			if (*backl)
				free(*backl);
			*backl = NULL;
			return (*line && (*line)[eof] != '\0');
		}
		buff[eof] = '\0';
		*line = ft_super_join(*line, buff);
	}
	eof = ft_where_nl(*line, '\n');
	if (eof >= 0)
	{
		free(*backl);
		*backl = ft_super_join(NULL, &(*line)[eof + 1]);
		(*line)[eof + 1] = '\0';
	}
	return (TRUE);
}

char	*get_next_line(int fd)
{
	static char	*backl[OPEN_MAX] = {0};
	char		*line;

	line = NULL;
	if (fd < OPEN_MAX && fd >= 0 && BUFFER_SIZE >= 1
		&& !ft_read(fd, &(backl[fd]), &line, 0))
	{
		free(line);
		line = NULL;
	}
	return (line);
}
