/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:04:38 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/19 16:00:50 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	game_free(t_game *game)
{
	free(game->minimap);
	free(game->rays);
	parse_free(game->map_info);
	mlx_delete_texture(game->no_texture);
	mlx_delete_texture(game->we_texture);
	mlx_delete_texture(game->so_texture);
	mlx_delete_texture(game->ea_texture);
	free(game);
}

int	main(int ac, char **av)
{
	t_parse	parse;
	t_game	*game;
	int		flager;

	flager = 0;
	flager = parse_entry(&parse, ac, av);
	if (!flager)
		return (EXIT_FAILURE);
	game = init_infos(&parse);
	if (!game->no_texture || !game->so_texture || !game->we_texture
		|| !game->ea_texture)
	{
		parse_free(game->map_info);
		write(2, "Error loading textures\n", 23);
		exit(1);
	}
	raycarting(game);
	mlx_key_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	game_free(game);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
