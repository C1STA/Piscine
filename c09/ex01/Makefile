NAME = libft.a

GCC =	gcc -Wall -Wextra -Werror

SRCS =	srcs/ft_putchar.c \
		srcs/ft_swap.c \
		srcs/ft_putstr.c \
		srcs/ft_strlen.c \
		srcs/ft_strcmp.c

INC =	-I includes/

OBJS =	$(SRCS:.c=.o)

AR =	ar rcs
LIB =	ranlib
RM =	rm -f

all:	$(NAME)

%.o: %.c
		$(GCC) $(INC) -c $< -o $@

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)
		$(LIB) $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re