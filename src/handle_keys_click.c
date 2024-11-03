#include <cub3D.h>

// void update_direction(t_game *game)
// {
//   // printf("x ---> %f\n", game->n_px); 
//   // printf("y ---> %f\n", game->n_py);
//   printf("update direction called\n");
//   double dx;
//   double dy;

//   dx = game->n_px - game->player_x;
//   dy = game->n_py - game->player_y;

//   double steps;
//   if(fabs(dx) > fabs(dy))
//     steps = fabs(dx);
//   else
//     steps = fabs(dy);
//   int i;
//   double x = game->player_x;
//   double y = game->player_y;
//   double x_inc = dx / steps;
//   double y_inc = dy / steps;
//   i = 0;
//   while(i < steps)
//   {
//     mlx_put_pixel(game->img, roundf(x), roundf(y), GREEN);
//     x += x_inc;
//     y += y_inc;
//     i++;    
//   }
// }

void right_arrow(t_game *game)
{
  game->turn_direction = 1;
}

void left_arrow(t_game *game)
{
  game->turn_direction = -1;
}

void up_arrow(t_game *game)
{
  game->walk_direction = 1;
}

void down_arrow(t_game *game)
{
  game->walk_direction = -1;
}
