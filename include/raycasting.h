#ifndef RAYCATSING_H
# define RAYCATSING_H

#include <cub3D.h>
#include <limits.h>

typedef struct s_game t_game;
typedef struct s_hor_intersection t_hor_intersection;
typedef struct s_ver_intersection t_ver_intersection;
typedef struct s_ray t_ray;
typedef struct s_player t_player;

void raycarting(t_game *game);
double deg_to_rad(double deg);
double rad_to_deg(double rad);
double get_new_x(t_game *game, double angle);
double get_new_y(t_game *game, double angle);
// void update_direction_dda(t_game *game);
void rebuild_map(t_game *game);
// bool is_player(char c);
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

#endif
