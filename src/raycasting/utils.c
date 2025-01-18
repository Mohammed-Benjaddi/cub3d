/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:02:38 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/17 22:09:01 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

double	deg_to_rad(double deg)
{
	return (deg * PI / 180.0);
}

double	rad_to_deg(double rad)
{
	return (rad * 180.0 / PI);
}

double	get_new_x(t_game *game, double angle)
{
	return (cos(angle) * (game->player.n_px - game->player.player_x)
		- sin(angle) * (game->player.n_py - game->player.player_y)
		+ game->player.player_x);
}

double	get_new_y(t_game *game, double angle)
{
	return (sin(angle) * (game->player.n_px - game->player.player_x)
		+ cos(angle) * (game->player.n_py - game->player.player_y)
		+ game->player.player_y);
}
