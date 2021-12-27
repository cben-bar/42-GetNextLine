/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:50:30 by cben-bar          #+#    #+#             */
/*   Updated: 2021/12/27 23:13:55 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int x)
{
	char	x_char;

	x_char = (unsigned char)x;
	while (*str != x_char)
	{
		if (*str == 0)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strndup(const char *src, int n)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!cpy || !src)
		return (NULL);
	while (src[i] && i < (size_t)n)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!cpy || !src)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*joined;
	size_t	len;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!str1 || !str2)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	while (str1[++i])
		joined[i] = str1[i];
	while (str2[++j])
		joined[i + j] = str2[j];
	joined[len] = '\0';
	return (joined);
}
