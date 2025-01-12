/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_click.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:21:32 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/12 21:53:00 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void w_key(t_game *game)
{
  double new_x;
  double new_y;

  new_x = game->player.player_x;
  new_y = game->player.player_y;
  game->player.walk_direction = 1;
  game->player.rotation_angle += game->player.turn_direction * game->player.rotation_speed;
	game->player.move_step = game->player.walk_direction * game->player.move_speed;
  new_x += cos(game->player.rotation_angle) * game->player.move_step;
	new_y += sin(game->player.rotation_angle) * game->player.move_step;
  if(!player_can_move(game, new_x, new_y))
    return;
  game->player.player_x = new_x;
  game->player.player_y = new_y;
}

void s_key(t_game *game)
{
  double new_x;
  double new_y;

  new_x = game->player.player_x;
  new_y = game->player.player_y;
  game->player.walk_direction = -1;
  game->player.rotation_angle += game->player.turn_direction * game->player.rotation_speed;
	game->player.move_step = game->player.walk_direction * game->player.move_speed;
	new_x += cos(game->player.rotation_angle) * game->player.move_step;
	new_y += sin(game->player.rotation_angle) * game->player.move_step;
  if(!player_can_move(game, new_x, new_y))
    return;
  game->player.player_x = new_x;
  game->player.player_y = new_y;
}

void a_key(t_game *game)
{
  double new_x;
  double new_y;

  new_x = game->player.player_x;
  new_y = game->player.player_y;
	game->player.walk_direction = 0;
  game->player.move_step = game->player.move_speed;
  new_x -= cos(game->player.rotation_angle + PI / 2) * game->player.move_step;
  new_y -= sin(game->player.rotation_angle + PI / 2) * game->player.move_step;
  if(!player_can_move(game, new_x, new_y))
    return;
  game->player.player_x = new_x;
  game->player.player_y = new_y;
}

void d_key(t_game *game)
{
  double new_x;
  double new_y;

  new_x = game->player.player_x;
  new_y = game->player.player_y;
  game->player.walk_direction = 0;
  game->player.move_step = game->player.move_speed;
  new_x += cos(game->player.rotation_angle + PI / 2) * game->player.move_step;
  new_y += sin(game->player.rotation_angle + PI / 2) * game->player.move_step;
  if(!player_can_move(game, new_x, new_y))
    return;
  game->player.player_x = new_x;
  game->player.player_y = new_y;
}
