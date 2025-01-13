/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows_click.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:23:56 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/13 18:27:40 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	right_arrow(t_game *game)
{
	game->player.turn_direction = 1;
	game->player.rotation_angle += game->player.turn_direction 
		* game->player.rotation_speed;
	game->player.move_step = game->player.walk_direction 
		* game->player.move_speed;
	game->player.player_x += cos(game->player.rotation_angle) 
		* game->player.move_step;
	game->player.player_y += sin(game->player.rotation_angle) 
		* game->player.move_step;
}

void	left_arrow(t_game *game)
{
	game->player.turn_direction = -1;
	game->player.rotation_angle += game->player.turn_direction 
		* game->player.rotation_speed;
	game->player.move_step = game->player.walk_direction 
		* game->player.move_speed;
	game->player.player_x += cos(game->player.rotation_angle) 
		* game->player.move_step;
	game->player.player_y += sin(game->player.rotation_angle) 
		* game->player.move_step;
}

bool check_width(t_game *game, int x, int y)
{
  int i;

  i = -2;
  while(i <= 2)
  {
    if (y / TILE_SIZE >= 0 && y / TILE_SIZE < (game->height / TILE_SIZE) 
      &&  (x + i) / TILE_SIZE >= 0 && (x + i) 
      / TILE_SIZE < (game->width / TILE_SIZE)) 
    {
      if(game->map[y / TILE_SIZE][(x + i) / TILE_SIZE] == '1')
        return false;
    }
    i++;
  }
  return true;
}

bool check_height(t_game *game, int x, int y)
{
  int i;
  
  i = -2;
  while(i <= 2)
  {
    if ((y + i) / TILE_SIZE >= 0 && (y + i) 
      / TILE_SIZE < (game->height / TILE_SIZE) 
      &&  (x / TILE_SIZE) >= 0 && (x / TILE_SIZE) < (game->width / TILE_SIZE)) 
    {
      if(game->map[(y + i) / TILE_SIZE][x / TILE_SIZE] == '1')
        return false;
    }
    i++;
  }
  return true;
}

bool player_can_move(t_game *game, double new_x, double new_y)
{
  int i;
  int x; 
  int y;

  i = -2;
  y = floor(new_y);
  x= floor(new_x);
  if(!check_width(game, x, y))
    return false;
  if(!check_height(game, x, y))
    return false;
  return true;
}
