/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:49:33 by cben-bar          #+#    #+#             */
/*   Updated: 2021/12/27 23:17:11 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*parse_str(char **s)
{
	char	*tmp;
	char	*display;

	tmp = *s;
	*s = ft_strdup(ft_strchr(tmp, '\n') + 1);
	display = ft_strndup(tmp, ft_strlen(tmp) - ft_strlen(*s));
	free(tmp);
	return (display);
}

static void	add_static(char **s, char *buffer)
{
	char	*tmp;

	if (*s)
	{
		tmp = *s;
		*s = ft_strjoin(tmp, buffer);
		free(tmp);
		return;
	}
	*s = ft_strdup(buffer);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*s[OPEN_MAX];
	int			ret;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if ((ret == -1) || (ret == 0 && s[fd] == NULL))
			return (NULL);
		buffer[ret] = '\0';
		add_static(&s[fd], buffer);
		if (ft_strchr(s[fd], '\n'))
			return (parse_str(&s[fd]));
	}
	if (s[fd] && !s[fd][0])
		tmp = NULL;
	else
		tmp = ft_strdup(s[fd]);
	free(s[fd]);
	s[fd] = NULL;
	return (tmp);
}
