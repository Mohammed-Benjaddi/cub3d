NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
MORE_FLAGS = -fsanitize=address -g

MLX_DIR	:= ~/MLX42
SRC_DIR = srcs
SRC_FILES = cub3D.c

HEADERS	:= -I ./include -I $(MLX_DIR)/include
LIBS	:= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MORE_FLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(MLX_DIR)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx