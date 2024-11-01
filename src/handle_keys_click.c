#include <cub3D.h>

void update_direction(t_game *game)
{
  printf("x ---> %f\n", game->n_px); 
  printf("y ---> %f\n", game->n_py);
  float dx;
  float dy;

  dx = game->n_px - game->player_x;
  dy = game->n_py - game->player_y;

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
  while(i < steps)
  {
    mlx_put_pixel(game->img, roundf(x), roundf(y), GREEN);
    x += x_inc;
    y += y_inc;
    i++;    
  }
}

void right_arrow(t_game *game)
{
  // game->turn_direction = 1;
  printf("rotation angle before ---> %f\n", game->rotation_angle);
  printf("speed --> %f\n", game->rotation_speed);
  game->rotation_angle += 1 * game->rotation_speed; 
  printf("rotation angle after ---> %f\n", game->rotation_angle);
  dda_algo(game);
  rebuild_map(game);
  // game->turn_direction = 0;
}

void left_arrow(t_game *game)
{
  // game->turn_direction = 1;
  printf("rotation angle before ---> %f\n", game->rotation_angle);
  printf("speed --> %f\n", game->rotation_speed);
  game->rotation_angle += -1 * game->rotation_speed; 
  printf("rotation angle after ---> %f\n", game->rotation_angle);
  dda_algo(game);
  rebuild_map(game);
  // game->turn_direction = 0;
}
