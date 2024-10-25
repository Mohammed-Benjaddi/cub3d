CC = cc
CFLAGS = -Wall -Wextra -Werror
MORE_FLAGS = -fsanitize=address -g

MLX_DIR	:= ~/MLX42
MLX_FLAGS = ~/MLX42/build/libmlx42.a

NAME = cub3D

SRC_DIR = srcs
SRC_FILES = cub3D.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

HEADERS_FILES = cub3D.h
HEADERS_DIR = include
HEADERS = -I $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))
MLX_HEADERS = -I $(MLX_DIR)/include

all: $(NAME)

libmlx:
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(MORE_FLAGS) -Imlx $(MLX_HEADERS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MORE_FLAGS) $(MLX_HEADERS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all libmlx clean fclean re
