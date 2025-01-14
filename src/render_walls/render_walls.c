/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 06:06:00 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/14 13:47:22 by mben-jad         ###   ########.fr       */
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
		tex_x = (int)(ray->wall_hit_y / tile_size * texture->width)
			% texture->width;
	else
		tex_x = (int)(ray->wall_hit_x / tile_size * texture->width)
			% texture->width;
	return (tex_x);
}

void	render_init(t_render *render, t_game *game, t_ray *rays)
{
	return;
}

void	render_walls(t_game *game, t_ray *rays)
{
	t_render		render;
	int				i;
	double			distance_proj_plane;
	double			proj_wall_height;
	double			perp_distance;
	int				wall_strip_height;
	int				wall_bottom_pixel;
	int				wall_top_pixel;
	int				y;
	int				tex_x;
	int				tex_y;
	uint32_t		color;
	mlx_texture_t	*texture;
	float			tile_size;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;

	texture = NULL;
	tile_size = TILE_SIZE;
	i = 0;
	floor_ceiling(game);
	while (i < NUM_RAYS)
	{
		perp_distance = rays[i].distance * cos(rays[i].ray_angle
				- game->player.rotation_angle);
		distance_proj_plane = (game->width / 2) * tan(game->fov / 2);
		proj_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
		wall_strip_height = (int)proj_wall_height;
		wall_bottom_pixel = get_bottom_pixel(game, wall_strip_height);
		wall_top_pixel = get_top_pixel(game, wall_strip_height);
		texture = game->ea_texture;
		if (rays[i].ray_angle >= 0 && rays[i].ray_angle < M_PI / 2)
			texture = game->ea_texture;
		else if (rays[i].ray_angle >= M_PI / 2 && rays[i].ray_angle < M_PI)
			texture = game->so_texture;
		else if (rays[i].ray_angle >= M_PI && rays[i].ray_angle < 3 * M_PI / 2)
			texture = game->we_texture;
		else if (rays[i].ray_angle >= 3 * M_PI / 2 && rays[i].ray_angle < 2
			* M_PI)
			texture = game->no_texture;
		tex_x = get_texture_x(&rays[i], texture, tile_size);
		y = wall_top_pixel;
		while (y < wall_bottom_pixel)
		{
			tex_y = (int)(((y - wall_top_pixel) / (double)wall_strip_height)
					* texture->height);
			tex_x = tex_x % texture->width;
			tex_y = tex_y % texture->height;
			r = texture->pixels[(tex_y * texture->width + tex_x) * 4 + 0];
			g = texture->pixels[(tex_y * texture->width + tex_x) * 4 + 1];
			b = texture->pixels[(tex_y * texture->width + tex_x) * 4 + 2];
			color = (r << 24) | (g << 16) | (b << 8) | 0XFF;
			ft_put_pixel(game->img, i, y, color);
			y++;
		}
		i++;
	}
}
