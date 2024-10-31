#include <raycasting.h>


// void  put_player(t_game *game, int y, int x)
// {
//   printf("-----------> here\n");
//   mlx_image_t* img;

//   img = mlx_new_image(game->mlx, 20, 20);
// 	if (!img || (mlx_image_to_window(game->mlx, img, y, x) < 0))
// 		perror("putting image to window failed");
// 	mlx_put_pixel(img, x, y, ft_pixel(rand() % 0xFF, rand() % 0xFF, rand() % 0xFF, rand() % 0xFF));
// }

// void ft_put_png(const char *path, t_game *game, int y, int x)
// {
//   mlx_texture_t* texture = mlx_load_png(path);
// 	if (!texture)
//     perror("texture issue");
// 	mlx_image_t* img = mlx_texture_to_image(game->mlx, texture);
// 	if (!img)
//     perror("convert texture to image failed");
// 	if (mlx_image_to_window(game->mlx, img, x, y) < 0)
//     perror("putting image to window failed");
// 	mlx_delete_texture(texture);
// }

int32_t ft_get_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void draw_background(t_game *game)
{
  int i;
  int j;
  

  i = 0;
  // image = mlx_new_image(game->mlx, game->width + 500, game->height + 200);
  // mlx_image_to_window(game->mlx, image, 0, 0);
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

void draw_direction(t_game *game)
{
  int i;
  int j;

  i = 0;
  j = 0;
  if(game->direction == 'N')
  {
    while(game->player_y + 15 - i > 0 && i < 50)
    {
      mlx_put_pixel(game->img, game->player_x, game->player_y - i, GREEN);
      i++;
    }
    game->n_px = game->player_x;
    game->n_py = game->y + 15.0 - i;
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
  draw_direction(game);
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
      else if(game->map[i][j] != '0')
        ft_put_player(game);
      j++;
      game->x += 30.0;
    }
    i++;
    game->y += 30.0;
  }
}

void raycarting(t_game *game)
{
  draw_map(game);
}