/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 18:06:37 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/09 18:01:59 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1643446566

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_static
{
	char		*buf;
	int			i;
	int			size;
	int			cpy;
}				t_static;

int				get_next_line(int const fd, char **line);

#endif
