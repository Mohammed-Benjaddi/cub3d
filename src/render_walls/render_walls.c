/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 06:06:00 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/19 00:31:23 by simo             ###   ########.fr       */
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
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				ft_put_pixel(game->img, j, i, game->map_info->ceiling_color);
			else
				ft_put_pixel(game->img, j, i, game->map_info->floor_color);
			j++;
		}
		i++;
	}
}

int	get_top_pixel(int wall_strip_hight)
{
	int	wall_top_pixel;

	wall_top_pixel = (HEIGHT / 2) - (wall_strip_hight / 2);
	return (wall_top_pixel);
}

int	get_bottom_pixel(int wall_strip_hight)
{
	int	wall_bottom_pixel;

	wall_bottom_pixel = (HEIGHT / 2) + (wall_strip_hight / 2);
	if (wall_bottom_pixel > HEIGHT)
		wall_bottom_pixel = HEIGHT;
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

void	render_walls(t_game *game, t_ray *rays)
{
	t_render	render;

	render.i = 0;
	render.distance_proj_plane = (WIDTH / 2.0) / tan(game->fov / 2.0);
	floor_ceiling(game);
	while (render.i < game->num_rays)
	{
		render_init(&render, game, rays);
		puter(&render, game, rays);
		render.tex_x = get_texture_x(&rays[render.i], render.texture,
				TILE_SIZE);
		render.y = render.wall_top_pixel;
		while (render.y < render.wall_bottom_pixel)
		{
			put_get_color(&render, game);
			render.y++;
		}
		render.i++;
	}
}
