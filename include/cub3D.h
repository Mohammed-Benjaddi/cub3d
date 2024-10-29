#ifndef CUB3D_H
# define CUB3D_H

#define RED   0xFF0000FF
#define WHITE 0xFFFFFFFF
#define BLACK 0x000000FF
#define GREEN 0xFF00FFFF

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
#include <libft.h>
#include <math.h>
// #include <raycasting.h>

typedef struct s_game
{
  int width;
  int height;
  int x;
  int y;
  char **map;
  mlx_t* mlx;
  char direction;
  int player_x;
  int player_y;
  double angle;
  int n_px;
  int n_py;
} t_game;

#endif
