NAME = do-op

CC = cc -Wall -Wextra -Werror -g

SRC = srcs/main.c \
		srcs/ops.c \
		srcs/utils.c \
		srcs/ft_do_op.c \

INC = -I inc/

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ)
			$(CC) $(OBJ) -o $(NAME)

%.o : %.c
			$(CC) $(INC) -c $< -o $@

clean :
		rm -f $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re