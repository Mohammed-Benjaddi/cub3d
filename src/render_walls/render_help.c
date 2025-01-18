/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:09:04 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/17 22:09:01 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/rendering_bonus.h"
#include <cub3D_bonus.h>

void	puter(t_render *render, t_game *game, t_ray *rays)
{
	if (rays[render->i].was_hit_vertical)
	{
		if (rays[render->i].is_ray_facing_right)
			render->texture = game->ea_texture;
		else
			render->texture = game->we_texture;
	}
	else
	{
		if (rays[render->i].is_ray_facing_down)
			render->texture = game->so_texture;
		else
			render->texture = game->no_texture;
	}
}

void	put_get_color(t_render *render, t_game *game)
{
	render->color = 0;
	render->tex_y = (int)(((render->y - render->wall_top_pixel)
				/ (double)render->wall_strip_height) * render->texture->height);
	render->r = render->texture->pixels[(render->tex_y * render->texture->width
			+ render->tex_x) * 4 + 0];
	render->g = render->texture->pixels[(render->tex_y * render->texture->width
			+ render->tex_x) * 4 + 1];
	render->b = render->texture->pixels[(render->tex_y * render->texture->width
			+ render->tex_x) * 4 + 2];
	render->a = render->texture->pixels[(render->tex_y * render->texture->width
			+ render->tex_x) * 4 + 3];
	render->color |= (render->r << 24);
	render->color |= (render->g << 16);
	render->color |= (render->b << 8);
	render->color |= render->a;
	ft_put_pixel(game->img, render->i, render->y, render->color);
}

void	render_init(t_render *render, t_game *game, t_ray *rays)
{
	render->perp_distance = rays[render->i].distance
		* cos(rays[render->i].ray_angle - game->player.rotation_angle);
	render->proj_wall_height = (TILE_SIZE / render->perp_distance)
		* render->distance_proj_plane;
	render->wall_strip_height = (int)render->proj_wall_height;
	render->wall_top_pixel = get_top_pixel(render->wall_strip_height);
	render->wall_bottom_pixel = get_bottom_pixel(render->wall_strip_height);
	return ;
}
