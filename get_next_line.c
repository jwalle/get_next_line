/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 17:44:58 by jwalle            #+#    #+#             */
/*   Updated: 2015/01/24 14:33:46 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_set_zero(t_static *toto)
{
	toto->cpy = 0;
	toto->size = 0;
	if (toto->tmp)
		free(toto->tmp);
	if (toto->buf)
		free(toto->buf);
//	if (toto->str)
//		free(toto->str);
	//if (toto)
	//	free(toto);
}



int		ft_cpy(t_static *toto, char **line)
{
	int		k;

	k = 0;
	if (toto->cpy >= toto->size)
	{
		ft_set_zero(toto);
		return (0);
	}
	while (toto->str[k] != '\0' && toto->str[k] != '\n')
		k++;
	*line = ft_strsub(toto->str, 0, k);
	toto->cpy += k + 1;
	toto->str = &(toto->str[k + 1]);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_static toto;

	if (!line || BUFF_SIZE < 1)
		return (-1);
	if (!toto.size)
	{
		toto.tmp = ft_strnew(BUFF_SIZE);
		while ((toto.i = read(fd, toto.tmp, BUFF_SIZE)) > 0)
		{
			toto.tmp[toto.i] = '\0';
			if (toto.size == 0)
				toto.buf = ft_strdup(toto.tmp);
			else
				toto.buf = ft_strjoin(toto.buf, toto.tmp);
			toto.size += toto.i;
			toto.tmp = ft_strnew(BUFF_SIZE);
		}
		toto.str = ft_strnew(toto.size);
		ft_strcpy(toto.str, toto.buf);
	}
	if (toto.i < 0)
		return (-1);
	return (ft_cpy(&toto, line));
}
