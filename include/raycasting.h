#ifndef RAYCATSING_H
# define RAYCATSING_H

#include <cub3D.h>

typedef struct s_game t_game;

# define PI 3.14159265358979323846
# define FOV 60 * PI / 180
# define NUM_RAYS 320

void raycarting(t_game *game);
float deg_to_rad(float deg);
float rad_to_deg(float rad);
float get_new_x(t_game *game, float angle);
float get_new_y(t_game *game, float angle);

#endif
