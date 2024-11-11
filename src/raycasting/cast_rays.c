#include <raycasting.h>

void put_ray(t_game *game, double rot_angle, int color) // update player direction using dda algo
{
  game->n_px  = game->player_x + cos(rot_angle) * 30;
  game->n_py = game->player_y + sin(rot_angle) * 30;
  double dx;
  double dy;
  dx = game->n_px - game->player_x;
  dy = game->n_py - game->player_y;
  double steps;
  if(fabs(dx) > fabs(dy))
    steps = fabs(dx);
  else
    steps = fabs(dy);
  int i;
  double x = game->player_x + 15;
  double y = game->player_y + 15;
  double x_inc = dx / steps;
  double y_inc = dy / steps;
  i = 0;
  while(i <= steps + 70)
  {
    ft_put_pixel(game->img, roundf(x), roundf(y), color);
    x += x_inc;
    y += y_inc;
    i++;    
  }
}

void cast_rays(t_game *game)
{
  game->rays_start = game->rotation_angle - (FOV / 2);
  game->rays_end = game->rotation_angle + (FOV / 2);
  while (game->rays_start < game->rays_end)
  {
    put_ray(game, game->rays_start, BEIGE);
    game->rays_start += (FOV / NUM_RAYS);
  }
}
