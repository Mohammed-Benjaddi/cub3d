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
# define MINIMAP_SCALE_FACTOR 0.2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
#include <libft.h>
#include <math.h>
#include <raycasting.h>

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
    float ray_angle;
    float wallHitX;
    float wallHitY;
    float distance;
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
  int x;
  int y;
  double p_x;
  double p_y;
  int x_inc;
  int y_inc;
  int width;
  int height;
  double n_px;
  double n_py;
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
} t_game;

// from raycasting.h

void raycarting(t_game *game);
double deg_to_rad(double deg);
double rad_to_deg(double rad);
double get_new_x(t_game *game, double angle);
double get_new_y(t_game *game, double angle);
void update_direction_dda(t_game *game, double rot_angle, int color);
void rebuild_map(t_game *game);
// bool is_player(char c);
void set_player_position(t_game *game);
void cast_rays(t_game *game);
bool is_player(char c);

// -----------------------------------

void right_arrow(t_game *game);
void left_arrow(t_game *game);
void w_key(t_game *game);
void s_key(t_game *game);
void d_key(t_game *game);
void a_key(t_game *game);
// void move_up(t_game *game);
// void move_down(t_game *game);
// void move_left(t_game *game);
// void move_right(t_game *game);

void render_walls(t_game *game, t_ray *rays);

// ------------------------------------------
void draw_minimap(t_game *game);
void init_minimap(t_game *game, t_minimap* minimap);

#endif
