NAME	:= cub3D
CFLAGS	:= #-Wextra -Wall -Werror #-Wunreachable-code -Ofast
MORE_FLAGS = #-fsanitize=address -g

MLX_DIR	:= ~/MLX42
SRC_DIR = src
CUB_FILES = cub3D.c handle_keys_click.c player_mvt.c
# LIBS = $(MLX_DIR)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm # for linux
LIBS	:= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm #for mac

RAYCAST_FILES = raycasting.c utils.c
LIBFT_FILES = ft_strdup.c ft_strlen.c
RAYCAST_SRC = $(addprefix $(SRC_DIR)/raycasting/, $(RAYCAST_FILES))
LIBFT_SRC = $(addprefix $(SRC_DIR)/libft/, $(LIBFT_FILES))
CUB_SRC = $(addprefix $(SRC_DIR)/, $(CUB_FILES))

HEADERS	:= -I ./include -I $(MLX_DIR)/include
SRC = $(CUB_SRC) $(LIBFT_SRC) $(RAYCAST_SRC)

OBJS	:= ${SRC:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

%.o: %.c ./include/cub3D.h 
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MORE_FLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	# rm -rf $(MLX_DIR)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
