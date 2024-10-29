#ifndef RAYCATSING_H
# define RAYCATSING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
#include <cub3D.h>

# define PI 3.14159265358979323846

void raycarting(t_game *game);
int deg_to_rad(int deg);
int rad_to_deg(int rad);

#endif
