/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_hor_intersections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:02:54 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/14 13:33:54 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_horizontal_intersection(t_game *game,
		t_hor_intersection *hor_inter, double ray_angle)
{
	hor_inter->found_horz_wall_hit = false;
	hor_inter->horzWallContent = 0;
	hor_inter->horzWallHitX = 0;
	hor_inter->horzWallHitY = 0;
	get_first_hor_inter(game, hor_inter, ray_angle);
	hor_inter->ystep = TILE_SIZE;
	if (is_ray_facing_up(ray_angle))
		hor_inter->ystep *= -1;
	else
		hor_inter->ystep *= 1;
	hor_inter->xstep = TILE_SIZE / tan(ray_angle);
	if (is_ray_facing_left(ray_angle) && hor_inter->xstep > 0)
		hor_inter->xstep *= -1;
	else
		hor_inter->xstep *= 1;
	if (is_ray_facing_right(ray_angle) && hor_inter->xstep < 0)
		hor_inter->xstep *= -1;
	else
		hor_inter->xstep *= 1;
	hor_inter->xToCheck = 0;
	hor_inter->yToCheck = 0;
	hor_inter->nextHorzTouchX = hor_inter->xintercept;
	hor_inter->nextHorzTouchY = hor_inter->yintercept;
}

void	init_vertical_intersection(t_game *game, t_ver_intersection *ver_inter,
		double ray_angle)
{
	ver_inter->foundVertWallHit = false;
	ver_inter->vertWallContent = 0;
	ver_inter->vertWallHitX = 0;
	ver_inter->vertWallHitY = 0;
	get_first_ver_inter(game, ver_inter, ray_angle);
	ver_inter->xstep = TILE_SIZE;
	if (is_ray_facing_left(ray_angle))
		ver_inter->xstep *= -1;
	else
		ver_inter->xstep *= 1;
	ver_inter->ystep = TILE_SIZE * tan(ray_angle);
	if (is_ray_facing_up(ray_angle) && ver_inter->ystep > 0)
		ver_inter->ystep *= -1;
	else
		ver_inter->ystep *= 1;
	if (is_ray_facing_down(ray_angle) && ver_inter->ystep < 0)
		ver_inter->ystep *= -1;
	else
		ver_inter->ystep *= 1;
	ver_inter->xToCheck = 0;
	ver_inter->yToCheck = 0;
	ver_inter->nextVertTouchX = ver_inter->xintercept;
	ver_inter->nextVertTouchY = ver_inter->yintercept;
}

bool	check_intersections(t_game *game, int x, int y)
{
	if (x >= 0 && x <= game->width && y >= 0 && y < game->height)
		return (true);
	return (false);
}

void	horizontal_intersection(t_game *game, 
	t_hor_intersection *hor_inter, double ray_angle)
{
	init_horizontal_intersection(game, hor_inter, ray_angle);
	while (check_intersections(game, 
			hor_inter->nextHorzTouchX, hor_inter->nextHorzTouchY))
	{
		hor_inter->xToCheck = hor_inter->nextHorzTouchX;
		if (is_ray_facing_up(ray_angle))
			hor_inter->yToCheck = hor_inter->nextHorzTouchY + -1;
		else
			hor_inter->yToCheck = hor_inter->nextHorzTouchY + 0;
		if (map_has_wall(game, hor_inter->xToCheck, hor_inter->yToCheck))
		{
			hor_inter->horzWallHitX = hor_inter->nextHorzTouchX;
			hor_inter->horzWallHitY = hor_inter->nextHorzTouchY;
			hor_inter->horzWallContent = 
				game->map[(int)floor(hor_inter->yToCheck 
					/ TILE_SIZE)][(int)floor(hor_inter->xToCheck / TILE_SIZE)];
			hor_inter->found_horz_wall_hit = true;
			break ;
		}
		else
		{
			hor_inter->nextHorzTouchX += hor_inter->xstep;
			hor_inter->nextHorzTouchY += hor_inter->ystep;
		}
	}
}

void	vertical_intersection(t_game *game, 
	t_ver_intersection *ver_inter, double ray_angle)
{
	init_vertical_intersection(game, ver_inter, ray_angle);
	while (ver_inter->nextVertTouchX >= 0
		&& ver_inter->nextVertTouchX <= game->width
		&& ver_inter->nextVertTouchY >= 0
		&& ver_inter->nextVertTouchY <= game->height)
	{
		if (is_ray_facing_left(ray_angle))
			ver_inter->xToCheck = ver_inter->nextVertTouchX + -1;
		else
			ver_inter->xToCheck = ver_inter->nextVertTouchX + 0;
		ver_inter->yToCheck = ver_inter->nextVertTouchY;
		if (map_has_wall(game, ver_inter->xToCheck, ver_inter->yToCheck))
		{
			ver_inter->vertWallHitX = ver_inter->nextVertTouchX;
			ver_inter->vertWallHitY = ver_inter->nextVertTouchY;
			ver_inter->vertWallContent = 
				game->map[(int)floor(ver_inter->yToCheck
					/ TILE_SIZE)][(int)floor(ver_inter->xToCheck / TILE_SIZE)];
			ver_inter->foundVertWallHit = true;
			break ;
		}
		ver_inter->nextVertTouchX += ver_inter->xstep;
		ver_inter->nextVertTouchY += ver_inter->ystep;
	}
}
