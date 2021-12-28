/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:59:33 by cben-bar          #+#    #+#             */
/*   Updated: 2021/12/28 20:30:55 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_dispatch(char **s)
{
	char	*tmp;
	char	*displayed_line;

	tmp = *s;
	*s = ft_strdup(ft_strchr(tmp, '\n') + 1);
	displayed_line = ft_strndup(tmp, ft_strlen(tmp) - ft_strlen(*s));
	free(tmp);
	return (displayed_line);
}

static void	add_static(char **s, char *buffer)
{
	char	*tmp;

	if (*s)
	{
		tmp = *s;
		*s = ft_strjoin(tmp, buffer);
		free(tmp);
		return ;
	}
	*s = ft_strdup(buffer);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*s[OPEN_MAX];
	int			rvr;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	rvr = 1;
	while (rvr > 0)
	{
		rvr = read(fd, buffer, BUFFER_SIZE);
		if ((rvr == -1) || (rvr == 0 && s[fd] == NULL))
			return (NULL);
		buffer[rvr] = '\0';
		add_static(&s[fd], buffer);
		if (ft_strchr(s[fd], '\n'))
			return (ft_dispatch(&s[fd]));
	}
	if (s[fd] && !s[fd][0])
		tmp = NULL;
	else
		tmp = ft_strdup(s[fd]);
	free(s[fd]);
	s[fd] = NULL;
	return (tmp);
}
