#include <raycasting.h>

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
      j++;
    }
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

void ft_put_pixel(mlx_image_t* image, int x, int y, int color)
{
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
  if (!game->background || (mlx_image_to_window(game->mlx, game->background, 0, 0)) < 0)
    perror("putting image to window failed");
  while(i < game->width)
  {
    j = 0;
    while(j < game->height)
    {
      ft_put_pixel(game->background, i, j, WHITE);
      j++;
    }
    i++;
  }
}
