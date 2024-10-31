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
  char direction;
  float player_x;
  float player_y;
  float angle;
  float n_px;
  float n_py;
} t_game;


// from raycasting.h

void raycarting(t_game *game);
float deg_to_rad(float deg);
float rad_to_deg(float rad);
float get_new_x(t_game *game, float angle);
float get_new_y(t_game *game, float angle);

// -----------------------------------



void hanle_left_arrow(t_game *game);


#endif
