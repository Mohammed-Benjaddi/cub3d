#include <raycasting.h>

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
