#include <raycasting.h>

float deg_to_rad(float deg)
{
  // printf("rad of %f is %f\n", deg, deg * PI / 180.0);
  return (deg * PI / 180.0);
}

float rad_to_deg(float rad)
{
  // printf("deg of %f is %f\n", rad, rad * 180.0 / PI);
  return (rad * 180.0 / PI);
}

float get_new_x(t_game *game, float angle)
{
  // return roundf(game->n_px * (cos(angle)) - game->n_py * (sin(angle)));
  // return (game->n_px - game->y) * cos(angle) - (game->n_py - game->y) * sin(angle) + game->x;
  return cos(angle) * (game->n_px - game->player_x) - sin(angle) * (game->n_py - game->player_y) + game->player_x;
}

float get_new_y(t_game *game, float angle)
{
  // return roundf((game->n_px * (sin(angle))) + (game->n_py * (cos(angle))));
  // return cos(angle) * (game->n_py - game->player_y) + sin(angle) + (game->n_px - game->player_y) + game->player_y;
  return floor(sin(angle) * (game->n_px - game->player_x) + cos(angle) * (game->n_py - game->player_y) + game->player_y);
}
