/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:28:13 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/19 16:00:30 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	normalize_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

double	calculate_distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	get_the_smaller_distance(t_game *game, t_ray *ray,
		double horz_hit_distance, double vert_hit_distance)
{
	t_hor_intersection	*hor_inter;
	t_ver_intersection	*ver_inter;

	hor_inter = &game->h_intersection;
	ver_inter = &game->v_intersection;
	if (vert_hit_distance < horz_hit_distance)
	{
		ray->distance = vert_hit_distance;
		ray->wall_hit_x = ver_inter->vert_wall_hit_x;
		ray->wall_hit_y = ver_inter->vert_wall_hit_y;
		ray->was_hit_vertical = true;
	}
	else
	{
		ray->distance = horz_hit_distance;
		ray->wall_hit_x = hor_inter->horz_wall_hit_x;
		ray->wall_hit_y = hor_inter->horz_wall_hit_y;
		ray->was_hit_vertical = false;
	}
	ray->is_ray_facing_down = is_ray_facing_down(ray->ray_angle);
	ray->is_ray_facing_up = is_ray_facing_up(ray->ray_angle);
	ray->is_ray_facing_left = is_ray_facing_left(ray->ray_angle);
	ray->is_ray_facing_right = is_ray_facing_right(ray->ray_angle);
}

void	cast_ray(t_game *game, t_ray *ray, float ray_angle)
{
	t_hor_intersection	*hor_inter;
	t_ver_intersection	*ver_inter;
	double				horz_hit_distance;
	double				vert_hit_distance;

	ray_angle = normalize_angle(ray_angle);
	hor_inter = &game->h_intersection;
	ver_inter = &game->v_intersection;
	horizontal_intersection(game, hor_inter, ray_angle);
	vertical_intersection(game, ver_inter, ray_angle);
	if (hor_inter->found_horz_wall_hit)
		horz_hit_distance = calculate_distance(game->player.player_x,
				game->player.player_y, hor_inter->horz_wall_hit_x,
				hor_inter->horz_wall_hit_y);
	else
		horz_hit_distance = INT_MAX;
	if (ver_inter->found_vert_wall_hit)
		vert_hit_distance = calculate_distance(game->player.player_x,
				game->player.player_y, ver_inter->vert_wall_hit_x,
				ver_inter->vert_wall_hit_y);
	else
		vert_hit_distance = INT_MAX;
	ray->ray_angle = ray_angle;
	get_the_smaller_distance(game, ray, horz_hit_distance, vert_hit_distance);
}

void	cast_rays(t_game *game)
{
	double	ray_angle;
	int		i;

	ray_angle = game->player.rotation_angle - (game->fov / 2);
	i = 0;
	while (i < game->num_rays)
	{
		cast_ray(game, &game->rays[i], ray_angle);
		ray_angle += (game->fov / game->num_rays);
		i++;
	}
}
