NAME = test_gnl

all : $(NAME)

$(NAME) :
	gcc -c -g -Wall -Werror -Wextra -I libft/includes/ get_next_line.c
	gcc -c -g -Wall -Werror -Wextra -I libft/includes/ main.c
	gcc -o $(NAME) -g get_next_line.o main.o -L libft/ -lft

clean:
	/bin/rm -f *.o
fclean:
	/bin/rm -f *.o
	/bin/rm -f $(NAME)

re: fclean all
