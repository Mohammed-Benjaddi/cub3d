/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:04:38 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/14 13:29:02 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_rotation(t_game *game)
{
	game->player.turn_direction = 0;
	game->player.walk_direction = 0;
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	init_rotation(game);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_RIGHT 
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		right_arrow(game);
	else if (keydata.key == MLX_KEY_LEFT 
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		left_arrow(game);
	else if (keydata.key == MLX_KEY_W 
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		w_key(game);
	else if (keydata.key == MLX_KEY_S 
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		s_key(game);
	else if (keydata.key == MLX_KEY_D 
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		d_key(game);
	else if (keydata.key == MLX_KEY_A 
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		a_key(game);
	rebuild_map(game);
}

void	set_direction(t_game *game, char c)
{
	if (c == 'N')
		game->player.rotation_angle = (3 * PI) / 2;
	else if (c == 'E')
		game->player.rotation_angle = 0;
	else if (c == 'S')
		game->player.rotation_angle = PI / 2;
	else
		game->player.rotation_angle = PI;
}

void	player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (game->height / TILE_SIZE))
	{
		j = 0;
		while (j < (game->width / TILE_SIZE))
		{
			if (is_player(game->map[i][j]))
				set_direction(game, game->map[i][j]);
			j++;
		}
		i++;
	}
}

t_game	*init_infos(t_parse *parse)
{
	t_game *game;
	game = malloc(sizeof(t_game));
	game->width = 720;
	game->height = 420;
	game->mlx = mlx_init(game->width , game->height, "MLX42", false);
	game->map = malloc(sizeof(char *) * 15);
	// game->map[0] = 	ft_strdup("111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	// game->map[1] = 	ft_strdup("1N0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
	// game->map[2] = 	ft_strdup("111111111111100000000001111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	game->map[0] = 	ft_strdup("111111111111111111111111");
	game->map[1] = 	ft_strdup("1001000S0000000000000001");
	game->map[2] = 	ft_strdup("100100000000000000000001");
	game->map[3] = 	ft_strdup("100100000000000000000001");
	game->map[4] = 	ft_strdup("111111100100000011100001");
	game->map[5] = 	ft_strdup("100000000011000011101111");
	game->map[6] = 	ft_strdup("111101111111101110000001");
	game->map[7] = 	ft_strdup("111101111111110111011001");
	game->map[8] = 	ft_strdup("110000001101010111000001");
	game->map[9] = 	ft_strdup("100000000000000110000011");
	game->map[10] = ft_strdup("100000000000000011010111");
	game->map[11] = ft_strdup("110000011101010111101111");
	game->map[12] = ft_strdup("111101111110101101111001");
	game->map[13] = ft_strdup("111111111111111111111111");
	game->map[14] = NULL;
	game->FOV = 60 * PI / 180;
	game->player.rotation_speed = 5;
	game->player.turn_direction = 0;
	game->player.walk_direction = 0;
	player_position(game);
	game->player.rotation_speed = 10 * (PI / 180);
	set_player_position(game);
	game->player.move_speed = 10;
	game->rays = malloc(sizeof(t_ray) * NUM_RAYS);
	game->map_info = parse;
	game->no_texture = mlx_load_png(game->map_info->no_texture);
	game->so_texture = mlx_load_png(game->map_info->so_texture);
  game->we_texture = mlx_load_png(game->map_info->we_texture);
  game->ea_texture = mlx_load_png(game->map_info->ea_texture);
	//init_minimap(game, &game->minimap);
	//game->minimap.p_x = 10;
	//game->minimap.p_y = 10;
	return game;
}

int	main(int ac, char** av)
{
	t_parse	parse;
	t_game	*game;
	int		flager;

	flager = 0;
	flager = parse_entry(&parse, ac, av);
	if (!flager)
		return (EXIT_FAILURE);
	game = init_infos(&parse);
	if (!game->no_texture || !game->so_texture 
		|| !game->we_texture || !game->ea_texture) 
	{
		printf("Error loading textures\n");
		exit(1);
	}
	raycarting(game);
	mlx_key_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
