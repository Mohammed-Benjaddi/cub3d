/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:01:37 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/19 00:31:23 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

void	set_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (is_player(game->map[i][j]))
			{
				game->player.player_x = (j * TILE_SIZE) + 15;
				game->player.player_y = (i * TILE_SIZE) + 15;
				return ;
			}
			j++;
		}
		i++;
	}
}

// void	update_direction_dda(t_game *game, double rot_angle, int color)
// 		// update player direction using dda algo
// {
// 	game->player.n_px = game->player.player_x + cos(rot_angle) * TILE_SIZE;
// 	game->player.n_py = game->player.player_y + sin(rot_angle) * TILE_SIZE;
// 	double dx;
// 	double dy;
// 	dx = game->player.n_px - game->player.player_x;
// 	dy = game->player.n_py - game->player.player_y;
// 	double steps;
// 	if (fabs(dx) > fabs(dy))
// 		steps = fabs(dx);
// 	else
// 		steps = fabs(dy);
// 	int i;
// 	double x = game->player.player_x;
// 	double y = game->player.player_y;
// 	double x_inc = dx / steps;
// 	double y_inc = dy / steps;
// 	i = 0;
// 	while (i <= steps + 70)
// 	{
// 		ft_put_pixel(game->img, roundf(x), roundf(y), color);
// 		x += x_inc;
// 		y += y_inc;
// 		i++;
// 	}
// }