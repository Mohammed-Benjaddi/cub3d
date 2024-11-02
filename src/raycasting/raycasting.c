#include <raycasting.h>

void draw_background(t_game *game)
{
  int i;
  int j;

  i = 0;
  while(i < game->width)
  {
    j = 0;
    while(j < game->height)
    {
      mlx_put_pixel(game->background, i, j, WHITE);
      j++;
    }
    i++;
  }
}

void ft_pixel(t_game *game, int x, int y)
{
  int i;
  int j;

  i = 0;
  while(i < 30)
  {
    j = 0;
    while (j < 30)
    {
      mlx_put_pixel(game->img, x + j, y + i, BLACK);
      j++;
    }
    i++;
  }
}

void dda_algo(t_game *game)
{
  game->n_px  = game->player_x + cos(game->rotation_angle) * 30;
  game->n_py = game->player_y + sin(game->rotation_angle) * 30;
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
  double x = game->player_x;
  double y = game->player_y;
  double x_inc = dx / steps;
  double y_inc = dy / steps;
  i = 0;
  while(i <= steps + 20)
  {
    mlx_put_pixel(game->img, roundf(x), roundf(y), GREEN);
    x += x_inc;
    y += y_inc;
    i++;    
  }
}

void ft_put_player(t_game *game, int x, int y)
{
  int i;
  int j;

  i = 0;
  j = 0;
  printf("--> %f\n", game->player_x);
  printf("--> %f\n", game->player_y);
  printf("x --> %d\n", x);
  printf("y --> %d\n", y);
  while(i < 30)
  {
    j = 0;
    while (j < 30)
    {
      if(j >= 12 && j <= 18 && i >= 12 && i <= 18)
        mlx_put_pixel(game->img, x + j, y + i, RED);
      j++;
    }
    i++;
  }
  // game->player_x = x + 15;
  // game->player_y = y + 15;
  dda_algo(game);
}

void draw_map(t_game *game)
{
  int i;
  int j;

  i = 0;
  if(!game->map)
    perror("Error: map not found\n");
  draw_background(game);
  game->img = mlx_new_image(game->mlx, game->width, game->height);
  if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
    perror("putting image to window failed");
  while(game->map[i])
  {
    j = 0;
    while(game->map[i][j])
    {
      if(game->map[i][j] == '1')
        ft_pixel(game, j * 30, i * 30);
      j++;
    }
    i++;
  }
}

bool is_player(char c)
{
  if(c == 'N' || c == 'S' || c == 'E' || c == 'W')
    return true;
  return false;
}

void put_player(t_game *game)
{
  ft_put_player(game, game->player_x, game->player_y);
}

void rebuild_map(t_game *game)
{
	mlx_delete_image(game->mlx, game->img);
  game->img = mlx_new_image(game->mlx, game->width, game->height);
  if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
    perror("putting image to window failed");
  draw_map(game);
  put_player(game); 
}

void raycarting(t_game *game)
{
  draw_map(game);
  put_player(game);
}
