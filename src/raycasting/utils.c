#include <raycasting.h>

double deg_to_rad(double deg)
{
  // printf("rad of %f is %f\n", deg, deg * PI / 180.0);
  return (deg * PI / 180.0);
}

double rad_to_deg(double rad)
{
  // printf("deg of %f is %f\n", rad, rad * 180.0 / PI);
  return (rad * 180.0 / PI);
}

double get_new_x(t_game *game, double angle)
{
  return cos(angle) * (game->player.n_px - game->player.player_x) - sin(angle) * (game->player.n_py - game->player.player_y) + game->player.player_x;
}    

double get_new_y(t_game *game, double angle)
{
  return sin(angle) * (game->player.n_px - game->player.player_x) + cos(angle) * (game->player.n_py - game->player.player_y) + game->player.player_y;
}
