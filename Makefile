NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I minilibx
LDFLAGS = -lXext -lX11 -lm

MLX = minilibx/libmlx.a
SRC =
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LDFLAGS) -o $(NAME)

%.o: %.c cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C minilibx

clean:
	rm -f $(OBJ)
	$(MAKE) -C minilibx clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
