/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_first_inters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:04:04 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/16 13:56:43 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	get_first_hor_inter(t_game *game, t_hor_intersection *hor_inter,
		double ray_angle)
{
	hor_inter->yintercept = floor(game->player.player_y / TILE_SIZE)
		* TILE_SIZE;
	if (is_ray_facing_down(ray_angle))
		hor_inter->yintercept += TILE_SIZE;
	else
		hor_inter->yintercept += 0;
	hor_inter->xintercept = game->player.player_x + (hor_inter->yintercept
			- game->player.player_y) / tan(ray_angle);
}

void	get_first_ver_inter(t_game *game, t_ver_intersection *ver_inter,
		double ray_angle)
{
	ver_inter->xintercept = floor(game->player.player_x / TILE_SIZE)
		* TILE_SIZE;
	if (is_ray_facing_right(ray_angle))
		ver_inter->xintercept += TILE_SIZE;
	else
		ver_inter->xintercept += 0;
	ver_inter->yintercept = game->player.player_y + (ver_inter->xintercept
			- game->player.player_x) * tan(ray_angle);
}

bool	map_has_wall(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || x > game->map_info->width * TILE_SIZE 
		|| y < 0 || y > game->map_info->height * TILE_SIZE)
		return (true);
	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if(map_x < 0 || map_y < 0 || map_y >= game->map_info->height
		|| map_x >= ft_strlen(game->map[map_y]))
		return (true);
	return (game->map[map_y][map_x] == '1');
}
