/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_hor_intersections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:02:54 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/16 11:22:44 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_horizontal_intersection(t_game *game,
		t_hor_intersection *hor_inter, double ray_angle)
{
	hor_inter->found_horz_wall_hit = false;
	hor_inter->horz_wall_hit_x = 0;
	hor_inter->horz_wall_hit_y = 0;
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
	hor_inter->x_check = 0;
	hor_inter->y_check = 0;
	hor_inter->next_horz_touch_x = hor_inter->xintercept;
	hor_inter->next_horz_touch_y = hor_inter->yintercept;
}

void	init_vertical_intersection(t_game *game, t_ver_intersection *ver_inter,
		double ray_angle)
{
	ver_inter->found_vert_wall_hit = false;
	ver_inter->vert_wall_hit_x = 0;
	ver_inter->vert_wall_hit_y = 0;
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
	ver_inter->x_check = 0;
	ver_inter->y_check = 0;
	ver_inter->next_vert_touch_x = ver_inter->xintercept;
	ver_inter->next_vert_touch_y = ver_inter->yintercept;
}

bool	check_intersections(t_game *game, double x, double y)
{
	// if (x >= 0 && x <= game->width && y >= 0 && y < game->height
	// printf("length ---> %d\n", ft_strlen(game->map[(int)floor(y / TILE_SIZE)]));
	if (x >= 0 && y >= 0 && floor(y / TILE_SIZE) < game->map_info->height
			&& floor(x / TILE_SIZE) < ft_strlen(game->map[(int)floor(y / TILE_SIZE)]))
			return (true);
	return (false);
}

void	horizontal_intersection(t_game *game, t_hor_intersection *hor_inter,
		double ray_angle)
{
	init_horizontal_intersection(game, hor_inter, ray_angle);
	while (check_intersections(game, hor_inter->next_horz_touch_x,
			hor_inter->next_horz_touch_y))
	{
		hor_inter->y_check = hor_inter->next_horz_touch_y;
		hor_inter->x_check = hor_inter->next_horz_touch_x;
		if (is_ray_facing_up(ray_angle))
			hor_inter->y_check--;
		if (map_has_wall(game, hor_inter->x_check, hor_inter->y_check))
		{
			hor_inter->horz_wall_hit_x = hor_inter->next_horz_touch_x;
			hor_inter->horz_wall_hit_y = hor_inter->next_horz_touch_y;
			hor_inter->found_horz_wall_hit = true;
			break ;
		}
		hor_inter->next_horz_touch_x += hor_inter->xstep;
		hor_inter->next_horz_touch_y += hor_inter->ystep;
	}
}

void	vertical_intersection(t_game *game, t_ver_intersection *ver_inter,
		double ray_angle)
{
	init_vertical_intersection(game, ver_inter, ray_angle);
	// while (ver_inter->next_vert_touch_x >= 0
	// 	&& ver_inter->next_vert_touch_x <= game->width
	// 	&& ver_inter->next_vert_touch_y >= 0
	// 	&& ver_inter->next_vert_touch_y <= game->height)
	while (check_intersections(game, ver_inter->next_vert_touch_x,
			ver_inter->next_vert_touch_y))
	{
		ver_inter->x_check = ver_inter->next_vert_touch_x;
		if (is_ray_facing_left(ray_angle))
			ver_inter->x_check--;
		ver_inter->y_check = ver_inter->next_vert_touch_y;
		if (map_has_wall(game, ver_inter->x_check, ver_inter->y_check))
		{
			ver_inter->vert_wall_hit_x = ver_inter->next_vert_touch_x;
			ver_inter->vert_wall_hit_y = ver_inter->next_vert_touch_y;
			ver_inter->found_vert_wall_hit = true;
			break ;
		}
		ver_inter->next_vert_touch_x += ver_inter->xstep;
		ver_inter->next_vert_touch_y += ver_inter->ystep;
	}
}
