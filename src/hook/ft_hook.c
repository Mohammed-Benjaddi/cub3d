/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:36:16 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/17 22:22:06 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

void	init_rotation(t_game *game)
{
	game->player.turn_direction = 0;
	game->player.walk_direction = 0;
}

// void esc_click(t_game *game)
// {
// 	parse_free(game->map_info);
// 	mlx_close_window(game->mlx);
// }

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	init_rotation(game);
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		right_arrow(game);
	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		left_arrow(game);
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		w_key(game);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		s_key(game);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		d_key(game);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
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
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->map_info = parse;
	game->width = game->map_info->width * TILE_SIZE;
	game->height = game->map_info->height * TILE_SIZE;
	game->num_rays = WIDTH;
	game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	game->map = game->map_info->original;
	game->fov = 60 * PI / 180;
	game->player.rotation_speed = 4;
	game->player.turn_direction = 0;
	game->player.walk_direction = 0;
	player_position(game);
	game->player.rotation_speed = 10 * (PI / 180);
	game->player.player_x = (game->map_info->player_x * TILE_SIZE + 15);
	game->player.player_y = (game->map_info->player_y * TILE_SIZE + 15);
	game->player.move_speed = 4;
	game->rays = malloc(sizeof(t_ray) * game->num_rays);
	game->no_texture = mlx_load_png(game->map_info->no_texture);
	game->so_texture = mlx_load_png(game->map_info->so_texture);
	game->we_texture = mlx_load_png(game->map_info->we_texture);
	game->ea_texture = mlx_load_png(game->map_info->ea_texture);
	game->minimap = malloc(sizeof(t_minimap));
	return (game);
}
