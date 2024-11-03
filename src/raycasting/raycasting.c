#include <raycasting.h>

void ft_put_pixel(mlx_image_t* image, int x, int y, int color)
{
  // printf("color :  %d\n", color);
  if(x < 0 || y < 0 || x >= image->width || y >= image->height)
    return;
  mlx_put_pixel(image, x, y, color);
}

void draw_background(t_game *game)
{
  int i;
  int j;

  i = 0;
  game->background = mlx_new_image(game->mlx, game->width + 500, game->height + 200);
  // mlx_image_to_window(game->mlx, game->background, 0, 0);
  if (!game->background || (mlx_image_to_window(game->mlx, game->background, 0, 0)) < 0)
    perror("putting image to window failed");
  while(i < game->width)
  {
    j = 0;
    while(j < game->height)
    {
      ft_put_pixel(game->background, i, j, WHITE);
      // mlx_put_pixel(game->background, i, j, WHITE);
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
      ft_put_pixel(game->img, x + j, y + i, BLACK);
      // mlx_put_pixel(game->img, x + j, y + i, BLACK);
      j++;
    }
    i++;
  }
}

void update_direction_dda(t_game *game) // update player direction using dda algo
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
  double x = game->player_x + 15;
  double y = game->player_y + 15;
  double x_inc = dx / steps;
  double y_inc = dy / steps;
  i = 0;
  while(i <= steps + 20)
  {
    // mlx_put_pixel(game->img, roundf(x), roundf(y), GREEN);
    ft_put_pixel(game->img, roundf(x), roundf(y), RED);
    x += x_inc;
    y += y_inc;
    i++;    
  }
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
  // ft_put_player(game, game->player_x, game->player_y);
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
        // mlx_put_pixel(game->img, game->player_x + j, game->player_y + i, RED);
        ft_put_pixel(game->img, game->player_x + j, game->player_y + i, RED);
      j++;
    }
    i++;
  }
  update_direction_dda(game);
}

void destroy_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->img);
	mlx_delete_image(game->mlx, game->background);
}

void rebuild_map(t_game *game)
{
  destroy_images(game);
  draw_map(game);
  put_player(game); 
}

void raycarting(t_game *game)
{
  draw_map(game);
  put_player(game);
}
