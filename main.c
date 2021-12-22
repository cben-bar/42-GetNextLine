/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:38:10 by cben-bar          #+#    #+#             */
/*   Updated: 2021/12/21 21:59:35 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
//	int	fd;
//	int	fd2;
//	int	fd3;
	int	fd4;
	int	fd5;
	int	fd6;
	int fd7;
	int	x;

	x = 20;
//	fd = open("nouveau_testament.txt", O_RDONLY);
//	fd2 = open("blop", O_RDONLY);
//	fd3 = open("blopblop", O_RDONLY);
	fd4 = open("41_with_nl", O_RDONLY);
	fd5 = open("42_with_nl", O_RDONLY);
	fd6 = open("43_with_nl", O_RDONLY);
/*	while (x-- && x > 3)
	{
	//	printf("%s\n", get_next_line(fd));
	//	printf("%s\n", get_next_line(fd2));
	//	printf("%s\n", get_next_line(fd3));
		printf("%s\n", get_next_line(1004));
		printf("%s\n", get_next_line(fd5));
		printf("%s\n", get_next_line(fd6));
	}
	while (x--)
	{
	//	printf("%s\n", get_next_line(fd));
	//	printf("%s\n", get_next_line(fd2));
	//	printf("%s\n", get_next_line(fd3));
		printf("%s\n", get_next_line(1004));
		printf("%s\n", get_next_line(fd5));
		printf("%s\n", get_next_line(fd6));
	}
	while (1)
	{
		printf("%s\n", get_next_line(1));
	}*/
	
	printf("1 ==> %s\n", get_next_line(1000));
	printf("2 ==> %s\n", get_next_line(fd4));
	printf("3 ==> %s\n", get_next_line(1001));
	printf("4 ==> %s\n", get_next_line(fd5));
	printf("5 ==> %s\n", get_next_line(1002));
	printf("6 ==> %s\n", get_next_line(fd6));
	printf("7 ==> %s\n", get_next_line(1003));
	printf("8 ==> %s\n", get_next_line(fd4));
	printf("9 ==> %s\n", get_next_line(1004));
	printf("10 => %s\n", get_next_line(fd5));
	printf("11 => %s\n", get_next_line(1005));
	printf("12 => %s\n", get_next_line(fd6));
	printf("13 => %s\n", get_next_line(fd4));
	printf("14 => %s\n", get_next_line(fd5));
	printf("15 => %s\n", get_next_line(fd6));
	fd7 = open("nl", O_RDWR);
	printf("16 => %s\n", get_next_line(1006));
	printf("17 => %s\n", get_next_line(fd7));
	printf("18 => %s\n", get_next_line(1007));
	printf("19 => %s\n", get_next_line(fd7));
	}
