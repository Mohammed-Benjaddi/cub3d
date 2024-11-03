#ifndef RAYCATSING_H
# define RAYCATSING_H

#include <cub3D.h>

typedef struct s_game t_game;

# define PI 3.14159265358979323846
# define FOV 60 * PI / 180
# define NUM_RAYS 320

void raycarting(t_game *game);
double deg_to_rad(double deg);
double rad_to_deg(double rad);
double get_new_x(t_game *game, double angle);
double get_new_y(t_game *game, double angle);
void update_direction_dda(t_game *game);
void rebuild_map(t_game *game);
bool is_player(char c);

#endif
