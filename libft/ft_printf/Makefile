NAME = libftprintf.a

SRC=ft_printf.c \
	ft_putchar_printf.c \
	ft_putnbr_printf.c \
	ft_putptr_printf.c \
	ft_putstr_printf.c \
	ft_putuint_printf.c \
	ft_putulhex_printf.c 

OBJ=$(SRC:.c=.o)

CC=cc

CFLAGS=-Wall -Wextra -Werror

INCLUDE=Makefile ft_printf.h

LIB=ar rcs

RM=rm -f

all:$(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:all clean fclean re
