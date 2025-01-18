/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:57:25 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/17 22:09:01 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

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
