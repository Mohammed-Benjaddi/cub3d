#include "cub3D.h"

void init_minimap(t_game *game, t_minimap* minimap)
{
  minimap->width = 140;
  minimap->height = 100;
  minimap->mm_img = mlx_new_image(game->mlx, minimap->width, minimap->height);
  if (!minimap->mm_img || (mlx_image_to_window(game->mlx, minimap->mm_img, 10, 10)) < 0)
    perror("putting image to window failed");
  minimap->x = 0;
  minimap->y = 0;
  minimap->x_inc = -3;
  minimap->y_inc = -2;
  // get_player_in_minimap(game, minimap);
  // minimap->p_x = minimap->width / 2;
  // minimap->p_y = minimap->height / 2;
}

void draw_direction_line(t_game *game, t_minimap *minimap, double rot_angle) // update player direction using dda algo
{
  minimap->n_px  = minimap->p_x + cos(rot_angle) * MM_TILE_SIZE;
  minimap->n_py = minimap->p_x + sin(rot_angle) * MM_TILE_SIZE;
  printf("---------------------------------------------------------------\n");
  printf("rot angle ---> %f\n", rot_angle);
  printf("n_px ---> %f | n_py ---> %f\n", minimap->n_px, minimap->n_py);
  printf("n_px ---> %f | n_py ---> %f\n", minimap->p_x, minimap->p_y);
  printf("---------------------------------------------------------------\n");
  double dx;
  double dy;
  dx = minimap->n_px - minimap->p_x;
  dy = minimap->n_py - minimap->p_y;
  double steps;
  if(fabs(dx) > fabs(dy))
    steps = fabs(dx);
  else
    steps = fabs(dy);
  int i;
  double x = minimap->p_x;
  double y = minimap->p_y;
  double x_inc = dx / steps;
  double y_inc = dy / steps;
  i = 0;
  while(i <= steps)
  {
    ft_put_pixel(minimap->mm_img, roundf(x), roundf(y), RED);
    x += x_inc;
    y += y_inc;
    i++;    
  }
}

void draw_line_mini(t_game *game, int x0, int y0, int x1, int y1)
{
  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = (x0 < x1) ? 1 : -1;
  int sy = (y0 < y1) ? 1 : -1;
  int err = dx - dy;

  while (true)
  {
    if(x0 < 0 || y0 < 0 || x0 >= 140 || y0 >= 100)
      return;
    ft_put_pixel(game->img, x0, y0, RED);
    if (x0 == x1 && y0 == y1)
        break;
    int e2 = 2 * err;
    if (e2 > -dy)
    {
        err -= dy;
        x0 += sx;
    }
    if (e2 < dx)
    {
        err += dx;
        y0 += sy;
    }
  }
}

void render_lin_mini(t_game *game)
{
  game->minimap.n_px = game->player.player_x + cos(game->player.rotation_angle) * 20;
  game->minimap.n_py = game->player.player_y + sin(game->player.rotation_angle) * 20;  
  draw_line_mini(game, game->minimap.p_x, game->minimap.p_x, game->minimap.n_px, game->minimap.n_py);
}

void draw_player(t_game *game, t_minimap *minimap)
{
  int i;
  int j;

  i = 0;
  j = 0;
  // printf("x --> %d | y --> %d\n", (int)roundf(minimap->p_x), (int)roundf(minimap->p_y));
  while (i < 8)
  {
    j = 0;
    while(j < 8)
    {
      // if(i >= 5 && i < 15 && j >= 5 && j < 15)
      //   ft_put_pixel(minimap->mm_img, (int)roundf(minimap->p_x) + j, (int)roundf(minimap->p_y) + i, RED);
      // else
      //   ft_put_pixel(minimap->mm_img, (int)roundf(minimap->p_x) + j, (int)roundf(minimap->p_y) + i, WHITE);
      ft_put_pixel(minimap->mm_img, (int)roundf(minimap->p_x) + j, (int)roundf(minimap->p_y) + i, RED);
      j++;
    }
    i++;
  }
  render_lin_mini(game);
  // draw_direction_line(game, minimap, game->player.rotation_angle);
}

int get_color(t_game *game, t_player player, t_minimap *minimap)
{
  int i;
  int j;

  i = floor(player.player_x / TILE_SIZE) + minimap->x_inc;
  j = floor(player.player_y / TILE_SIZE) + minimap->y_inc;
  if(i < 0 || j < 0 || i >= (game->width / TILE_SIZE) || j >= (game->height / TILE_SIZE))
    return BLACK;
  else if(game->map[j][i] == '1')
    return BLACK;
  // if(game->map[j][i] == 'S')
    // printf("%d | %d\n",i, j);
  // else if(game->map[j][i] == '0')
  return WHITE;

  // draw_player(game, minimap, i, j);

  // return 0;
}

void draw_square(t_game *game, int x, int y)
{
  int i;
  int j;
  int color;
  t_minimap *minimap;

  minimap = &game->minimap;
  color = get_color(game, game->player, minimap);
  if(color == 0)
    return;
  i = 0;
  while(i < MM_TILE_SIZE)
  {
    j = 0;
    while(j < MM_TILE_SIZE)
    {
      ft_put_pixel(minimap->mm_img, minimap->x + j, minimap->y + i, color);
      j++;
    }
    i++;
  }
}

#define MINIMAP_SCALE 0.2

void draw_minimap(t_game *game)
{
    int minimap_width = game->width * MINIMAP_SCALE;
    int minimap_height = game->height * MINIMAP_SCALE;
    int tile_size = TILE_SIZE * MINIMAP_SCALE;
    int i, j;
    t_minimap *minimap;

    minimap = &game->minimap;
    init_minimap(game, minimap);

    for (i = 0; i < game->height / TILE_SIZE; i++)
    {
        for (j = 0; j < game->width / TILE_SIZE; j++)
        {
            int color = 0xFFFFFF; // Default color for empty space
            if (game->map[i][j] == '1')
                color = 0x000000; // Color for walls
            else if (game->map[i][j] == 'S')
                color = 0xFF0000; // Color for player

            // Draw the tile on the minimap
            // mlx_image_to_window(game->img, game->win, game->img, j * TILE_SIZE, i * TILE_SIZE);
            
        }
    }
}

// void draw_minimap(t_game *game)
// {
  
  // int i;
  // int j;
  // t_minimap *minimap;

  // i = 0;
  // j = 0;
  // minimap = &game->minimap;
  // // minimap->x = 0;
  // // minimap->y = 0;
  // init_minimap(game, minimap);
  // while(i < 5)
  // {
  //   j = 0;
  //   minimap->x = 0;
  //   minimap->x_inc = -3;
  //   while(j < 7)
  //   {
  //     draw_square(game, i, j);
  //     j++;
  //     minimap->x += MM_TILE_SIZE;
  //     minimap->x_inc++;
  //   }
  //   i++;
  //   minimap->y += MM_TILE_SIZE;
  //   minimap->y_inc++;
  // }
  // draw_player(game, minimap);
// }
