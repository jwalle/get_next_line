NAME = test_gnl

SRC = get_next_line.c

OBJ = get_next_line.o

all : $(NAME)

$(NAME) :
	gcc -c -g -Wall -Werror -Wextra -I libft/includes/ $(SRC) main.c
	gcc -o $(NAME) $(OBJ) main.o -L libft/ -lft
	/bin/rm -f *.o 

clean:
	/bin/rm -f $(OBJ) 
fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)

re: fclean all clean
