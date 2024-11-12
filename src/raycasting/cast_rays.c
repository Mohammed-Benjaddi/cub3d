#include <raycasting.h>

// void put_ray(t_game *game, double rot_angle, int color) // update player direction using dda algo
// {
//   bool wall_hit_x = false;
//   bool wall_hit_y = false;
//   // player is facing down
//   if(to_down())
//   {

//   }

  // game->n_px  = game->player_x + cos(rot_angle) * 30;
  // game->n_py = game->player_y + sin(rot_angle) * 30;
  // double dx;
  // double dy;
  // dx = game->n_px - game->player_x;
  // dy = game->n_py - game->player_y;
  // double steps;
  // if(fabs(dx) > fabs(dy))
  //   steps = fabs(dx);
  // else
  //   steps = fabs(dy);
  // int i;
  // double x = game->player_x + 15;
  // double y = game->player_y + 15;
  // double x_inc = dx / steps;
  // double y_inc = dy / steps;
  // i = 0;
  // while(i <= steps + 70)
  // {
  //   ft_put_pixel(game->img, roundf(x), roundf(y), color);
  //   x += x_inc;
  //   y += y_inc;
  //   i++;    
  // }
// }

bool to_down(double angle)
{
  if(angle > 0 && angle < M_PI)
    return true;
  return false;
}

bool to_right(double angle)
{
  if(angle < 0.5 * M_PI || angle > 1.5 * M_PI)
    return true;
  return false;
}

bool map_has_wall(t_game *game, int x, int y)
{
  if(y < 0 || y >= game->height / 30 || x < 0 || x >= game->width / 30)
    return true;
  printf("map --> %c | x --> %d | y --> %d\n", game->map[y][x], x, y);
  if(game->map[y][x] == '1')
    return true;
  return false;
}

void put_ray(t_game *game, double rays_start, int color)
{
  (void) rays_start;
  (void) color;
  double first_inter_x;
  double first_inter_y;
  double next_hor_x;
  double next_hor_y;

  next_hor_x = 0;
  next_hor_y = 0;
  if(!to_down(game->rotation_angle))
    first_inter_y = floor(game->player_y / TILE_SIZE) * TILE_SIZE - 1;
  else if(to_down(game->rotation_angle))
    first_inter_y = floor(game->player_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
  first_inter_x = floor((first_inter_y - game->player_y) / tan(game->rotation_angle)) + game->player_x;
  next_hor_x = first_inter_x;
  next_hor_y = first_inter_y;

  // printf("x ---> %f\n", next_hor_x);
  // printf("y ---> %f\n", next_hor_y);
  // printf("--------------------------------------------\n");
  double xa;
  double ya;
  if(!to_down(game->rotation_angle))
    ya = -TILE_SIZE;
  else if(to_down(game->rotation_angle))
    ya = TILE_SIZE;
  xa = TILE_SIZE / tan(game->rotation_angle);
  while(next_hor_x <= game->width && next_hor_x >= 0 && next_hor_y <= game->height && next_hor_y >= 0)
  {
    if(map_has_wall(game, (int)floor(next_hor_x / 30), (int)floor(next_hor_y / 30)))
    {
      printf("wall touched\n");
      game->wall_hit_x = next_hor_x;
      game->wall_hit_y = next_hor_y;
      break;
    }
    next_hor_x += xa;
    next_hor_y += ya;
    game->wall_hit_x = next_hor_x; 
    game->wall_hit_y = next_hor_y;
  }
}

void cast_rays(t_game *game)
{
  game->rays_start = game->rotation_angle - (FOV / 2);
  game->rays_end = game->rotation_angle + (FOV / 2);
  int i = 0;
  while (i < 1 && game->rays_start < game->rays_end)
  {
    put_ray(game, game->rays_start, BEIGE);
    printf("x ---> %f\n", game->wall_hit_x);
    printf("y ---> %f\n", game->wall_hit_y);
    printf("--------------------------------------------\n");
    game->rays_start += (FOV / NUM_RAYS);
    i++;
  }
}
