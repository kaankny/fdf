NAME		=	libftprintf.a
SRC			=	ft_printf.c ft_putchar.c ft_putstring.c ft_putnumber.c ft_putunsignedint.c ft_puthex.c ft_putpointer.c ft_itoa.c
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
AR			=	ar rc

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) -c $(SRC)
	$(AR) $(NAME) $(OBJ)
			
clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
