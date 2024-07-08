MLX = lib/MLX42

MLX_MAKE = make --no-print-directory -C MLX42

LIBFT = libft/libft.a

LIBFT_MAKE = make --no-print-directory -C libft

FT_PRINTF = libft/ft_printf/ft_printf.h

FT_PRINTF_MAKE = make --no-print-directory -C ft_printf

NAME = so_long

SRC = so_long.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

CC = cc

RM = rm -f

INCLUDE = so_long.h Makefile

%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

all: library $(NAME)

$(NAME): $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -O $(NAME)

libft:
		$(LIBFT_MAKE)

clean:
			$(RM) $(OBJ)
			$(LIBFT_MAKE) clean

fclean: clean
				$(RM) $(NAME)
				$(LIBFT_MAKE) fclean

library:
			make -C libft

re: fclean all

.PHONY: all clean fclean re libft ft_printf
