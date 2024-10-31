#include <cub3D.h>

void update_direction(t_game *game)
{
  float dx;
  float dy;

  printf("npx ==> %f | npy ==> %f\n", game->n_px, game->n_py);
  printf("player_x ==> %f | player_y ==> %f\n", game->player_x, game->player_y);

  dx = game->n_px - game->player_x;
  dy = game->n_py - game->player_y;

  printf("dx ==> %f | dy ==> %f\n", dx, dy);
  float steps;

  if(fabs(dx) > fabs(dy))
    steps = fabs(dx);
  else
    steps = fabs(dy);

  int i;
  float x = game->player_x;
  float y = game->player_y;
  float x_inc = dx / steps;
  float y_inc = dy / steps;

  i = 0;
  printf("steps --> %f\n", steps);
  while(i < steps)
  {
    mlx_put_pixel(game->img, roundf(x), roundf(y), GREEN);
    x += x_inc;
    y += y_inc;
    i++;
  }
  printf("direction updated\n");
}

void hanle_left_arrow(t_game *game)
{
  
  float rotate_angle = 9.0;
  printf("_____________ %f\n", get_new_x(game, deg_to_rad(rotate_angle)));
  game->n_px = get_new_x(game, deg_to_rad(rotate_angle));
  game->n_py = get_new_y(game, deg_to_rad(rotate_angle));
  update_direction(game);
}
