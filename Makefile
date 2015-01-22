all : 
	gcc -c -g -Wall -Werror -Wextra -I libft/includes/ get_next_line.c
	gcc -c -g -Wall -Werror -Wextra -I libft/includes/ main.c
	gcc -o test_gnl -g get_next_line.o main.o -L libft/ -lft
#	rm -rf *.o

