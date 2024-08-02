MLX = MLX42/build/libmlx42.a

LIBFT = libft/libft.a

LIBFT_MAKE = make --no-print-directory -C libft

FT_PRINTF = libft/ft_printf/libftprintf.a

NAME = so_long

SRC = so_long.c \
	  so_long_utils.c \
	  so_long_utils_2.c \
	  so_long_free.c \
	  so_long_checks_map.c \
	  so_long_flood_fill.c \
	  so_long_mlx.c \
	  so_long_movements.c \
	  so_long_end_game.c \
	  so_long_write_error.c

		
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -Wunreachable-code -O3 #-fsanitize=address

LFLAGS = -ldl -lglfw -lm

CC = cc

RM = rm -f

INCLUDE = so_long.h Makefile

all: library $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) $(MLX) $(LFLAGS) -o $(NAME)

$(LIBFT):
		$(LIBFT_MAKE)

%.o: %.c $(INCLUDE)
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
