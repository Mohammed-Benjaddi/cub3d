NAME	:= cub3D
CFLAGS	:= #-Wextra -Wall -Werror #-Wunreachable-code -Ofast
MORE_FLAGS = -fsanitize=address -g

MLX_DIR	:= ~/MLX42
SRC_DIR = src
CUB_FILES = cub3D.c ./render_walls/render_walls.c
# LIBS = $(MLX_DIR)/build/libmlx42.a -Iinclude -ldl -L/goinfre/bbelarra/homebrew/Cellar/glfw/3.4/lib/ -lglfw -pthread -lm # for linux
LIBS	:= $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm #for mac

RAYCAST_FILES = raycasting.c utils.c draw.c player_utils.c cast_rays.c check_directions.c vert_hor_intersections.c calc_first_inters.c
RENDER_WALLS_FILES = render_walls.c
PARSE_FILES = parse.c nsew_check.c utils/utils_0.c utils/utils_1.c utils/utils_2.c utils/utils_3.c utils/utils_4.c utils/utils_5.c utils/help.c  utils/rgb_help.c
LIBFT_FILES = ft_strdup.c ft_strlen.c ft_substr.c ft_atoi.c
GNL_FILES = get_next_line.c get_next_line_utils.c
MINIMAP_FILES = minimap.c dda_algo.c
HOOK_FILES = handle_keys_click.c arrows_click.c

RAYCAST_SRC = $(addprefix $(SRC_DIR)/raycasting/, $(RAYCAST_FILES))
LIBFT_SRC = $(addprefix $(SRC_DIR)/libft/, $(LIBFT_FILES))
GNL_SRC = $(addprefix $(SRC_DIR)/gnl/, $(GNL_FILES))
PARSE_SRC = $(addprefix $(SRC_DIR)/parsing/, $(PARSE_FILES))
CUB_SRC = $(addprefix $(SRC_DIR)/, $(CUB_FILES))
MINIMAP_SRC = $(addprefix $(SRC_DIR)/minimap/, $(MINIMAP_FILES))
HOOK_SRC = $(addprefix $(SRC_DIR)/hook/, $(HOOK_FILES))

HEADERS	:= -I ./include -I $(MLX_DIR)/include
SRC = $(CUB_SRC) $(LIBFT_SRC) $(RAYCAST_SRC) $(PARSE_SRC) $(GNL_SRC) $(MINIMAP_SRC) $(HOOK_SRC)

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
