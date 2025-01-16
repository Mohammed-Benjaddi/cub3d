/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 06:06:00 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/14 15:57:50 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/rendering.h"
#include <cub3D.h>

void	floor_ceiling(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (i < game->height / 2)
				ft_put_pixel(game->img, j, i, game->map_info->ceiling_color);
			else
				ft_put_pixel(game->img, j, i, game->map_info->floor_color);
			j++;
		}
		i++;
	}
}

int	get_top_pixel(t_game *game, int wall_strip_hight)
{
	int	wall_top_pixel;

	wall_top_pixel = (game->height / 2) - (wall_strip_hight / 2);
	if (wall_top_pixel < 0)
		wall_top_pixel = 0;
	return (wall_top_pixel);
}

int	get_bottom_pixel(t_game *game, int wall_strip_hight)
{
	int	wall_bottom_pixel;

	wall_bottom_pixel = (game->height / 2) + (wall_strip_hight / 2);
	if (wall_bottom_pixel > game->height)
		wall_bottom_pixel = game->height;
	return (wall_bottom_pixel);
}

int	get_texture_x(t_ray *ray, mlx_texture_t *texture, float tile_size)
{
	int	tex_x;

	if (ray->was_hit_vertical)
		tex_x = (int)((ray->wall_hit_y / tile_size) * texture->width)
			% texture->width;
	else
		tex_x = (int)((ray->wall_hit_x / tile_size) * texture->width)
			% texture->width;
	if (tex_x < 0)
		tex_x += texture->width;
	return (tex_x);
}

void	render_init(t_render *render, t_game *game, t_ray *rays)
{
	render->perp_distance = rays[render->i].distance
		* cos(rays[render->i].ray_angle - game->player.rotation_angle);
	render->proj_wall_height = (TILE_SIZE / render->perp_distance)
		* render->distance_proj_plane;
	render->wall_strip_height = (int)render->proj_wall_height;
	render->wall_top_pixel = get_top_pixel(game, render->wall_strip_height);
	render->wall_bottom_pixel = get_bottom_pixel(game,
			render->wall_strip_height);
	return ;
}

void	render_walls(t_game *game, t_ray *rays)
{
	t_render	render;
	render.i = 0;
	render.distance_proj_plane = (game->width / 2.0) / tan(game->fov / 2.0);
	floor_ceiling(game);
	while (render.i < game->num_rays)
	{
		render_init(&render, game, rays);
		if (rays[render.i].was_hit_vertical)
		{
			if (rays[render.i].is_ray_facing_right)
				render.texture = game->ea_texture;
			else
				render.texture = game->we_texture;
		}
		else
		{
			if (rays[render.i].is_ray_facing_down)
				render.texture = game->so_texture;
			else
				render.texture = game->no_texture;
		}
		render.tex_x = get_texture_x(&rays[render.i], render.texture,
				TILE_SIZE);
		render.y = render.wall_top_pixel;
		while (render.y < render.wall_bottom_pixel)
		{
			render.tex_y = (int)(((render.y - render.wall_top_pixel)
						/ (double)render.wall_strip_height)
					* render.texture->height);
			render.r = render.texture->pixels[(render.tex_y
					* render.texture->width + render.tex_x) * 4 + 0];
			render.g = render.texture->pixels[(render.tex_y
					* render.texture->width + render.tex_x) * 4 + 1];
			render.b = render.texture->pixels[(render.tex_y
					* render.texture->width + render.tex_x) * 4 + 2];
			render.a = render.texture->pixels[(render.tex_y
					* render.texture->width + render.tex_x) * 4 + 3];
			render.color = (render.r << 24) | (render.g << 16)
				| (render.b << 8) | render.a;
			ft_put_pixel(game->img, render.i, render.y, render.color);
			render.y++;
		}
		render.i++;
	}
}
