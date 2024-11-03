#ifndef CUB3D_H
# define CUB3D_H

#define RED   0xFF0000FF
#define WHITE 0xFFFFFFFF
#define BLACK 0x000000FF
#define GREEN 0x00cb12
#define BLUE 0x006cff
#define CYAN 0x00ffec

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
#include <libft.h>
#include <math.h>
#include <raycasting.h>

typedef struct s_game
{
  int width;
  int height;
  int x;
  int y;
  char **map;
  mlx_t* mlx;
  mlx_image_t *img;
  mlx_image_t* background;
  mlx_image_t* player;
  char direction;
  double player_x;
  double player_y;
  double angle;
  double n_px;
  double n_py;
  double rotation_speed;
  int turn_direction;
  double rotation_angle;
  int walk_direction;
  double move_speed;
  double move_step;
} t_game;

// from raycasting.h

void raycarting(t_game *game);
double deg_to_rad(double deg);
double rad_to_deg(double rad);
double get_new_x(t_game *game, double angle);
double get_new_y(t_game *game, double angle);
void update_direction_dda(t_game *game);
void rebuild_map(t_game *game);
bool is_player(char c);

// -----------------------------------

void right_arrow(t_game *game);
void left_arrow(t_game *game);
void up_arrow(t_game *game);
void down_arrow(t_game *game);
void move_up(t_game *game);
void move_down(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);

#endif
