NAME    = fractol

CFLAGS  = -Wall -Wextra -Werror # -fsanitize=address
SRC		= main.c mandelbrot.c mlx_win.c draw_fractals.c julia.c burning_ship.c
OBJ		= ${SRC:.c=.o}
LIBFT = libft/lib/libft.a
MLX = MLX42/lib/libmlx42.a

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@gcc $(CFLAGS) $(OBJ) $(MLX) -lglfw -o $(NAME) $(LIBFT)

$(LIBFT):
	@make -C libft/src

clean:
	@rm -rf $(OBJ)
	@make -C libft/src clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/src fclean

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re
