#include <raycasting.h>

void destroy_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->img);
	mlx_delete_image(game->mlx, game->background);
	mlx_delete_image(game->mlx, game->minimap.mm_img);
}

void rebuild_map(t_game *game)
{
  destroy_images(game);
  draw_map(game);
  // put_player(game);
  cast_rays(game);
	render_walls(game, game->rays);
  draw_minimap(game);
}

void raycarting(t_game *game)
{
  game->minimap.p_x = 60;
  game->minimap.p_y = 40;
  draw_map(game);
  put_player(game);
  cast_rays(game);
	render_walls(game, game->rays);
  draw_minimap(game);
}
