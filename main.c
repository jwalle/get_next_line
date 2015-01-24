/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 16:58:15 by jwalle            #+#    #+#             */
/*   Updated: 2015/01/24 14:38:36 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"


int		test_files(char *file_name)
{	
	int fd;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("open() error file : %s", file_name);
		return (1);
	}
	return (fd);
}

int		main(int ac, char **av)
{
	int fd;
	int	fd2;
	int fd3;
	char *line;
	int	i;
	int err;
	char *files[] = {"./cor/1_8", "./cor/2_8", "./cor/5_8","./cor/1_16","./cor/2_16","./cor/5_16", "./cor/1_long", "./cor/sansn", "./cor/multi1","./cor/multi2","./cor/multi3"};

	av[1] = av[1];
	i = 0;
	err = 1;
	if (ac == 3)
	{
		fd = test_files(files[8]);
		fd2 = test_files(files[9]);
		fd3 = test_files(files[10]);
		err = get_next_line(fd, &line);
		printf("#%d# : \033[33m%s\033[0m\n", err, line);
		err = get_next_line(fd, &line);
		printf("#%d# : \033[33m%s\033[0m\n", err, line);
		free((void*)line);
		err = get_next_line(fd2, &line);
		printf("#%d# : \033[33m%s\033[0m\n", err, line);
		free((void*)line);
		err = get_next_line(fd3, &line);
		printf("#%d# : \033[33m%s\033[0m\n", err, line);
		free((void*)line);
		err = get_next_line(fd, &line);
		printf("#%d# : \033[33m%s\033[0m\n", err, line);
		err = get_next_line(fd, &line);
		printf("#%d# : \033[33m%s\033[0m\n", err, line);
		free((void*)line);
		err = get_next_line(fd2, &line);
		printf("#%d# : \033[33m%s\033[0m\n", err, line);
		return (0);
	}

	if (ac == 2)
	{
		while (err)
		{
			err = get_next_line(-42, &line);
			if (err > 0)
				printf("#%d# : \033[33m%s\033[0m\n", err, line);
		}
		printf("#%d# : \033[33m%s\033[0m\n", err, line);
		printf("\x1B[31m#%d# : Fin du fichier %d. \x1B[31m\n", err, i + 1);
		free((void *)line);	
	return (0);
	}

	while (i < 8)
	{
		fd = test_files(files[i]);
		err = 1;
		while (err > 0)
		{
			err = get_next_line(fd, &line);
			if (err > 0)
			{
				printf("#%d# : \033[33m%s\033[0m\n", err, line);
				/*if(line)
					free((void*)line);*/
			}
			else
			{
				printf("\x1B[31m#%d# : Fin du fichier %d. \x1B[0m\n", err, i + 1);
				i++;
				err = -1;
			}
		}
	}
	printf("\x1B[32m0 argument pour test sur fichier, 1 argument pour entree standard, 2 arguments pour multi-fd.\x1B[0m\n");
	if (close(fd) == -1)
	{
		printf("close() error");
		return (1);
	}
	return (0);
}
