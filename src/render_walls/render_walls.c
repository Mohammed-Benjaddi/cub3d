#include <cub3D.h>

void floor_ceiling(t_game *game)
{
  int i;
  int j;

  // int R = 255, G = 0, B = 0;
  // int color = (R << 16) | (G << 8) | B | 0xFF;

  // int R1 = 0, G2 = 0, B3 = 255;
  // int color1 = (R1 << 16) | (G2 << 8) | B3;

  i = 0;
  j = 0;
  while(i < game->height)
  {
    j = 0;
    while(j < game->width)
    {
      if(i < game->height / 2)
        ft_put_pixel(game->img, j, i, RED);
      else
        ft_put_pixel(game->img, j, i, CYAN);
      j++;
    }
    i++;
  }
}

int get_top_pixel(t_game *game, int wall_strip_hight)
{
  int wall_top_pixel;

  wall_top_pixel = (game->height / 2) - (wall_strip_hight / 2);
  if(wall_top_pixel < 0)
    wall_top_pixel = 0;
  return wall_top_pixel;
}

int get_bottom_pixel(t_game *game, int wall_strip_hight)
{
  int wall_bottom_pixel;
  wall_bottom_pixel = (game->height / 2) + (wall_strip_hight / 2);
  if(wall_bottom_pixel > game->height)
    wall_bottom_pixel = game->height;
  return wall_bottom_pixel;
}

void render_walls(t_game *game, t_ray *rays)
{
  int i;
  double distance_proj_plane;
  double proj_wall_height;
  double perp_distance;
  int wall_strip_hight;
  // int wall_top_pixel;
  int wall_bottom_pixel;
  int y;

  i = 0;
  floor_ceiling(game);
  while(i < NUM_RAYS)
  {
    perp_distance = rays[i].distance * cos(rays[i].ray_angle - game->player.rotation_angle);
    distance_proj_plane = (game->width / 2) * tan(FOV / 2);
    proj_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
    wall_strip_hight = (int)proj_wall_height;
    wall_bottom_pixel = get_bottom_pixel(game, wall_strip_hight);
    y = get_top_pixel(game, wall_strip_hight);
    while(y < wall_bottom_pixel)
      ft_put_pixel(game->img, i, y++, WHITE);
    i++;
  }
}
