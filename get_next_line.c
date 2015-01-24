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

void	ft_set_zero(t_static *toto)
{
	toto->cpy = 0;
	toto->size = 0;
}

int		ft_cpy(t_static *toto, char **line)
{
	int		k;

	k = 0;
	if (toto->cpy >= toto->size)
	{
		ft_set_zero(toto);
		ft_strclr(toto->buf);
		toto->str = NULL;
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

	*line = ft_strnew(BUFF_SIZE + 10);
	ft_strclr(*line);
	if (!line || BUFF_SIZE < 1)
		return (-1);
	if (!toto.size)
	{
		toto.buf = ft_strnew(0);
		toto.tmp = ft_strnew(BUFF_SIZE + 10);
		while ((toto.i = read(fd, toto.tmp, BUFF_SIZE + 10)) > 0)
		{
			toto.tmp[toto.i] = '\0';
			if (toto.size == 0)
				toto.buf = ft_strdup(toto.tmp);
			else
				toto.buf = ft_strjoin(toto.buf, toto.tmp);
			toto.size += toto.i;
		}
		toto.str = ft_strnew(toto.size);
		toto.str = ft_strdup(toto.buf);
	}
	if (toto.i < 0)
		return (-1);
	return (ft_cpy(&toto, line));
}
