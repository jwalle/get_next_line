/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 17:44:58 by jwalle            #+#    #+#             */
/*   Updated: 2015/02/09 14:10:35 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_set_zero(t_static *toto)
{
	toto->cpy = 0;
	toto->size = 0;
	free(toto->buf);
}

int		ft_cpy(t_static *toto, char **line)
{
	int		k;
	char	*temp;

	k = 0;
	if (toto->cpy >= toto->size)
	{
		ft_set_zero(toto);
		return (0);
	}
	while (toto->buf[k] != '\0' && toto->buf[k] != '\n')
		k++;
	*line = ft_strsub(toto->buf, 0, k);
	toto->cpy += k + 1;
	temp = ft_strdup(&(toto->buf[k + 1]));
	free (toto->buf);
	toto->buf = ft_strdup(temp);
	free (temp);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_static toto;

	if (!line || BUFF_SIZE < 1)
		return (-1);
	if (!toto.size)
	{
		while ((toto.i = read(fd, toto.tmp, BUFF_SIZE)) > 0)
		{
			toto.tmp[toto.i] = '\0';
			if (!toto.size)
				toto.buf = ft_strdup(toto.tmp);
			else
				toto.buf = ft_strjoin(toto.buf, toto.tmp);
			toto.size += toto.i;
		}
	}
	if (toto.i < 0)
		return (-1);
	return (ft_cpy(&toto, line));
}
