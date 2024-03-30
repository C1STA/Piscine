NAME = rush-02

CC = cc -Wall -Wextra -Werror -g

SRC = src/main.c \
		src/fill.c \
		src/free.c \
		src/utils.c \
		src/utils2.c \
		src/parsing.c \
		src/ft_split.c \
		src/fill_numbers.c \
		src/parse_numbers.c \
		src/get_dictionary.c

INC = -I inc/

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ)
			$(CC) $(OBJ) -o $(NAME)

%.o : %.c
			$(CC) $(INC) -c $< -o $@

valgrind :
			valgrind --leak-check=full --track-fds=yes -s ./$(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re