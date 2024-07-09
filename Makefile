MLX = MLX42/build/libmlx42.a

LIBFT = libft/libft.a

LIBFT_MAKE = make --no-print-directory -C libft

FT_PRINTF = libft/ft_printf/libftprintf.a

NAME = so_long

SRC = so_long.c \
	  so_long_utils.c
		
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

LFLAGS = -ldl -lglfw -lm

CC = cc

RM = rm -f

INCLUDE = so_long.h Makefile

all: library $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX) $(LFLAGS) -o $(NAME)

$(LIBFT):
		$(LIBFT_MAKE)

%.o: %.c
		$(CC) $(CFLAGS) -I ./include -I	./lib/MLX42/include	-c $< -o $@

clean:
			$(RM) $(OBJ)
			$(LIBFT_MAKE) clean

fclean: clean
				$(RM) $(NAME)
				$(LIBFT_MAKE) fclean

library:
			make -C libft

re: fclean all

.PHONY: all clean fclean re libft ft_printf get_next_line mlx
