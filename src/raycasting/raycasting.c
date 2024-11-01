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

void ft_pixel(t_game *game)
{
  int i;
  int j;

  i = 0;
  while(i < 30)
  {
    j = 0;
    while (j < 30)
    {
      mlx_put_pixel(game->img, game->x + j, game->y + i, BLACK);
      j++;
    }
    i++;
  }
}

void dda_algo(t_game *game)
{
  game->n_px  = game->player_x + cos(game->rotation_angle) * 30;
  game->n_py = game->player_y + sin(game->rotation_angle) * 30;
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
  while(i <= steps + 20)
  {
    mlx_put_pixel(game->img, roundf(x), roundf(y), GREEN);
    x += x_inc;
    y += y_inc;
    i++;    
  }
}

void ft_put_player(t_game *game)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while(i < 30)
  {
    j = 0;
    while (j < 30)
    {
      if(j >= 12 && j <= 18 && i >= 12 && i <= 18)
        mlx_put_pixel(game->img, game->x + j, game->y + i, RED);
      j++;
    }
    i++;
  }
  game->player_x = game->x + 15;
  game->player_y = game->y + 15;
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
    game->x = 0.0;
    while(game->map[i][j])
    {
      if(game->map[i][j] == '1')
        ft_pixel(game);
      j++;
      game->x += 30.0;
    }
    i++;
    game->y += 30.0;
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
  int i;
  int j;

  i = 0;
  j = 0;
  game->x = 0.0;
  game->y = 0.0;
  while(game->map[i])
  {
    j = 0;
    game->x = 0.0;
    while(game->map[i][j])
    {
      if(is_player(game->map[i][j]))
        ft_put_player(game);
      j++;
      game->x += 30.0;
    }
    i++;
    game->y += 30.0;
  }
}

void rebuild_map(t_game *game)
{
	mlx_delete_image(game->mlx, game->img);
  game->img = mlx_new_image(game->mlx, game->width, game->height);
  if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
    perror("putting image to window failed");
  game->x = 0;
  game->y = 0;
  draw_map(game);
  printf("image created again\n");
  put_player(game); 
}

void raycarting(t_game *game)
{
  draw_map(game);
  put_player(game);
}
