#include <cub3D.h>
#include <raycasting.h>

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		right_arrow(game);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		left_arrow(game);
}

t_game *init_infos()
{
	t_game *game;
	game = malloc(sizeof(t_game));
	game->width = 1000;
	game->height = 620;
	game->mlx = mlx_init(game->width , game->height, "MLX42", true);
	game->map = malloc(sizeof(char *) * 15);
	game->map[0] = 	ft_strdup("111111111111111111111111");
	game->map[1] = 	ft_strdup("100000000011000000000001");
	game->map[2] = 	ft_strdup("101100000111000000N00001");
	game->map[3] = 	ft_strdup("100100000000000000000001");
	game->map[4] = 	ft_strdup("111111111011000011100001");
	game->map[5] = 	ft_strdup("100000000011000011101111");
	game->map[6] = 	ft_strdup("111101111111101110000001");
	game->map[7] = 	ft_strdup("111101111111110111011001");
	game->map[8] = 	ft_strdup("110000001101010111000001");
	game->map[9] = 	ft_strdup("100000000000000110000011");
	game->map[10] = ft_strdup("100000000000000011010111");
	game->map[11] = ft_strdup("11000001110101011111011");
	game->map[12] = ft_strdup("111101111110101101111001");
	game->map[13] = ft_strdup("111111111111111111111111");
	game->map[14] = NULL;
	game->x = 0.0;
	game->y = 0.0;
	game->angle = 90;
	game->direction = 'N';
	game->rotation_speed = 5;
	game->turn_direction = 0;
	game->walk_direction = 0;
	game->rotation_angle = PI / 2;
	game->rotation_speed = 9 * (PI / 180);
	printf("init rotation angle ---> %f\n", game->rotation_angle);
	printf("init rotation speed ---> %f\n", game->rotation_speed);
	game->background = mlx_new_image(game->mlx, game->width + 500, game->height + 200);
  mlx_image_to_window(game->mlx, game->background, 0, 0);
	game->img = mlx_new_image(game->mlx, game->width, game->height);
  if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
    perror("putting image to window failed");
	return game;
}

int32_t main(void)
{
	t_game *game;
	game = init_infos();
	raycarting(game);

	mlx_key_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
