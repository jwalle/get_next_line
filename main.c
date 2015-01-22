/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 16:58:15 by jwalle            #+#    #+#             */
/*   Updated: 2014/11/28 14:30:55 by jwalle           ###   ########.fr       */
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
		printf("open() error");
		return (1);
	}
	return (fd);
}

int		main()
{
	int fd;
	char *line;
	int	i;
	int err;
	char *files[] = {"./cor/1_8", "./cor/2_8", "./cor/5_8","./cor/1_16","./cor/2_16","./cor/5_16", "./cor/1_long"};

	i = 0;
	err = 1;
	while (i < 7)
	{
		fd = test_files(files[i]);
		err = 1;
		while (err > 0)
		{
			err = get_next_line(fd, &line);
			if (err > 0)
			{
				printf("#%d# : \033[33m%s\033[0m\n", err, line);
				free((void*)line);
			}
			else
			{
				printf("\x1B[31m#%d# : Fin du fichier %d. \x1B[31m\n", err, i + 1);
				i++;
				err = -1;
			}
		}
	}
	if (close(fd) == -1)
	{
		printf("close() error");
		return (1);
	}
	return (0);
}
