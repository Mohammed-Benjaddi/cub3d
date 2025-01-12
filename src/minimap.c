#include "cub3D.h"

void init_minimap(t_game *game, t_minimap *minimap)
{
  minimap->x = game->player.player_x / 2;
  minimap->y = game->player.player_y / 2;
  minimap->h = 6 * (TILE_SIZE / 2);
  minimap->v = 4 * (TILE_SIZE / 2);
  minimap->width = minimap->h * 2;
  minimap->height = minimap->v * 2;
  minimap->mm_img = mlx_new_image(game->mlx, minimap->width, minimap->height);
  if (!minimap->mm_img || (mlx_image_to_window(game->mlx, minimap->mm_img, 10, 10)) < 0)
    perror("putting image to window failed");
}

void minimap_put_pixel(t_game *game, t_minimap *minimap, uint32_t color)
{
  if (minimap->s_x - (minimap->x - minimap->h) < 0 
  || minimap->s_y - (minimap->y - minimap->v) < 0 
  || minimap->s_x - (minimap->x - minimap->h) >= 180
  || minimap->s_y - (minimap->y - minimap->v) >= 120) 
    return;
  mlx_put_pixel(minimap->mm_img, minimap->s_x - (minimap->x - minimap->h),
                minimap->s_y - (minimap->y - minimap->v), color);
}

t_dda_algo init_dda(t_minimap *minimap, double rot_angle)
{
  t_dda_algo dda;

  dda.n_px  = minimap->h + cos(rot_angle) * (TILE_SIZE / 2);
  dda.n_py = minimap->v + sin(rot_angle) * (TILE_SIZE / 2);
  dda.dx = dda.n_px - minimap->h;
  dda.dy = dda.n_py - minimap->v;
  if(fabs(dda.dx) > fabs(dda.dy))
    dda.steps = fabs(dda.dx);
  else
    dda.steps = fabs(dda.dy);
  dda.x = minimap->h;
  dda.y = minimap->v;
  dda.x_inc = dda.dx / dda.steps;
  dda.y_inc = dda.dy / dda.steps;
  return dda;
}

void dda(t_minimap *minimap, double rot_angle)
{
  t_dda_algo dda;
  int i;

  i = 0;
  dda = init_dda(minimap, rot_angle);
  while(i <= dda.steps)
  {
    ft_put_pixel(minimap->mm_img, roundf(dda.x), roundf(dda.y), RED);
    dda.x += dda.x_inc;
    dda.y += dda.y_inc;
    i++;    
  }
}

void put_player_minimap(t_game *game, t_minimap *minimap)
{
  int i;
  int j;

  i = -3;
  while (i < 3)
  {
    j = -3;
    while (j < 3)
    {
      mlx_put_pixel(minimap->mm_img, minimap->h + j, minimap->v + i, RED);
      j++;
    }
    i++;
  }
  dda(minimap, game->player.rotation_angle);
}

void draw_minimap_pix(t_game *game, t_minimap *minimap)
{
  if ((minimap->s_x / (TILE_SIZE / 2)) >= 0 
      && (minimap->s_y / (TILE_SIZE / 2)) >= 0 
      && (minimap->s_y / (TILE_SIZE / 2)) < 14 
      && (minimap->s_x / (TILE_SIZE / 2)) < (int)ft_strlen(game->map[(int)(minimap->s_y / (TILE_SIZE / 2))]) 
      && game->map[(int)(minimap->s_y / (TILE_SIZE / 2))][(int)(minimap->s_x / (TILE_SIZE / 2))] == '1')
    minimap_put_pixel(game, minimap, BLACK);
  else
    minimap_put_pixel(game, minimap, WHITE);
}
void draw_minimap(t_game *game)
{
  t_minimap *minimap = &game->minimap;

  init_minimap(game, minimap);
  minimap->s_y = minimap->y - minimap->v;
  minimap->end_y = minimap->y + minimap->v;
  while (minimap->s_y < minimap->end_y)
  {
    minimap->s_x = minimap->x - minimap->h;
    minimap->end_x = minimap->x + minimap->h;
    while (minimap->s_x < minimap->end_x)
    {
      draw_minimap_pix(game, minimap);
      put_player_minimap(game, minimap);
      minimap->s_x++;
    }
    minimap->s_y++;
  }
}
