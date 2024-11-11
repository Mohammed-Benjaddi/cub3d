#ifndef RAYCATSING_H
# define RAYCATSING_H

#include <cub3D.h>

typedef struct s_game t_game;

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

#endif
