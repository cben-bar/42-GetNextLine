/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:38:10 by cben-bar          #+#    #+#             */
/*   Updated: 2021/12/19 22:44:12 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int	fd2;
	int	fd3;
	int	x;

	x = 10;
	fd = open("nouveau_testament.txt", O_RDONLY);
	fd2 = open("blop", O_RDONLY);
	fd3 = open("blopblop", O_RDONLY);
	while (x-- && x > 3)
	{
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd2));
		printf("%s\n", get_next_line(fd3));
	}
	while (x--)
	{
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd2));
		printf("%s\n", get_next_line(fd3));
	}
	while (1)
	{
		printf("%s\n", get_next_line(1));
	}
}
