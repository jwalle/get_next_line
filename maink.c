#include <stdio.h>
#include "libft/includes/libft.h"
#include <fcntl.h>

int			get_next_line(int const fd, char **line);

int main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;
	(void)ac;
	(void)av;

	fd = open(av[1], O_RDONLY);
	//fd = 1;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%d : %s\n", ret, line);
		free(line);
	}

	return (0);
}
