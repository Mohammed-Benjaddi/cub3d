#ifndef CUB3D_H
# define CUB3D_H

#define RED   0xFF0000FF
#define WHITE 0xFFFFFFFF
#define BLACK 0x000000FF
#define GREEN 0x00cb12
#define BLUE 0x006cff
#define CYAN 0x00ffec
#define BEIGE 0xFFB38E

# define PI 3.14159265358979323846
# define FOV 60 * PI / 180
# define NUM_RAYS 1200
# define TILE_SIZE 30
# define MM_TILE_SIZE 20

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
#include <libft.h>
#include <math.h>
#include "parsing.h"

typedef struct s_dda_algo
{
  int n_px;
  int n_py;
  double dx;
  double dy;
  double steps;
  double x;
  double y;
  double x_inc;
  double y_inc;
} t_dda_algo;

typedef struct s_hor_intersection 
{
  bool foundHorzWallHit;
  int horzWallContent;
  double nextHorzTouchX;
  double nextHorzTouchY;
  double horzWallHitX;
  double horzWallHitY;
  double xintercept;
  double yintercept;
  double xstep;
  double ystep;
  double xToCheck;
  double yToCheck;
} t_hor_intersection;

typedef struct s_ver_intersection 
{
  bool foundVertWallHit;
  int vertWallContent;
  double nextVertTouchX;
  double nextVertTouchY;
  double vertWallHitX;
  double vertWallHitY;
  double xintercept;
  double yintercept;
  double xstep;
  double ystep;
  double xToCheck;
  double yToCheck;
} t_ver_intersection;

typedef struct s_ray {
    double ray_angle;
    double wallHitX;
    double wallHitY;
    double distance;
    int wasHitVertical;
    int isRayFacingUp;
    int isRayFacingDown;
    int isRayFacingLeft;
    int isRayFacingRight;
    int wallHitContent;
} t_ray;


typedef struct s_player
{
  double player_x;
  double player_y;
  double n_px;
  double n_py;
  double rotation_speed;
  int turn_direction;
  double rotation_angle;
  int walk_direction;
  double move_speed;
  double move_step;
} t_player;

typedef struct s_minimap
{
  double p_x;
  double p_y;
  int x_inc;
  int y_inc;
  double n_px;
  double n_py;
  int v; 
  int h;
  int width;
  int height;
  double x; 
  double y; 
  double s_y;
  double s_x; 
  double end_x;
  double end_y;
  mlx_image_t* mm_img;
} t_minimap;

typedef struct s_game
{
  int width;
  int height;
  char **map;
  mlx_t* mlx;
  mlx_image_t *img;
  mlx_image_t* background;
  t_player player;
  t_hor_intersection h_intersection;
  t_ver_intersection v_intersection;
  t_ray *rays;
  t_minimap minimap;
  t_parse *map_info;
  mlx_texture_t *no_texture;
  mlx_texture_t *so_texture;
  mlx_texture_t *we_texture;
  mlx_texture_t *ea_texture;
} t_game;

void raycarting(t_game *game);
double deg_to_rad(double deg);
double rad_to_deg(double rad);
double get_new_x(t_game *game, double angle);
double get_new_y(t_game *game, double angle);
void rebuild_map(t_game *game);
void set_player_position(t_game *game);
void draw_map(t_game *game);
void draw_background(t_game *game);
void ft_put_pixel(mlx_image_t* image, int x, int y, int color);
void put_player(t_game *game);
void cast_rays(t_game *game);
void horizontal_intersection(t_game *game, t_hor_intersection *hor_inter, double ray_angle);
void vertical_intersection(t_game *game, t_ver_intersection *ver_inter, double ray_angle);
int isRayFacingDown(double ray_angle);
int isRayFacingUp(double ray_angle);
int isRayFacingRight(double ray_angle);
int isRayFacingLeft(double ray_angle);
bool is_player(char c);
void right_arrow(t_game *game);
void left_arrow(t_game *game);
void w_key(t_game *game);
void s_key(t_game *game);
void d_key(t_game *game);
void a_key(t_game *game);
void render_walls(t_game *game, t_ray *rays);
void draw_minimap(t_game *game);
void init_minimap(t_game *game, t_minimap* minimap);

#endif
