/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:57:25 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/19 00:31:23 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_ray_facing_down(double ray_angle)
{
	if (ray_angle > 0 && ray_angle < M_PI)
		return (true);
	return (false);
}

int	is_ray_facing_up(double ray_angle)
{
	if (ray_angle > 0 && ray_angle < M_PI)
		return (false);
	return (true);
}

int	is_ray_facing_right(double ray_angle)
{
	if (ray_angle < 0.5 * PI || ray_angle > 1.5 * PI)
		return (true);
	return (false);
}

int	is_ray_facing_left(double ray_angle)
{
	if (ray_angle < 0.5 * PI || ray_angle > 1.5 * PI)
		return (false);
	return (true);
}
