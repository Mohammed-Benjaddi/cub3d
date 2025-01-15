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

int get_texture_x(t_ray *ray, mlx_texture_t *texture, float tile_size)
{
    int tex_x;

    if (ray->was_hit_vertical) {
        // For vertical walls, use the y-coordinate of the wall hit
        tex_x = (int)((ray->wall_hit_y / tile_size) * texture->width) % texture->width;
    } else {
        // For horizontal walls, use the x-coordinate of the wall hit
        tex_x = (int)((ray->wall_hit_x / tile_size) * texture->width) % texture->width;
    }

    // Ensure tex_x is within valid bounds
    if (tex_x < 0) {
        tex_x += texture->width;
    }

    return tex_x;
}


void	render_init(t_render *render, t_game *game, t_ray *rays)
{
	return ;
}

void render_walls(t_game *game, t_ray *rays)
{
    int i;
    double perp_distance;
    double distance_proj_plane;
    double proj_wall_height;
    int wall_strip_height;
    int wall_top_pixel;
    int wall_bottom_pixel;
    int tex_x, tex_y;
    uint32_t color;
    mlx_texture_t *texture;

    // Calculate the distance to the projection plane once
    distance_proj_plane = (game->width / 2.0) / tan(game->fov / 2.0);

    // Draw the ceiling and floor first
    floor_ceiling(game);

    for (i = 0; i < game->num_rays; i++)
    {
        // Correct perpendicular distance to avoid fish-eye effect
        perp_distance = rays[i].distance * cos(rays[i].ray_angle - game->player.rotation_angle);

        // Calculate projected wall height
        proj_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
        wall_strip_height = (int)proj_wall_height;

        // Calculate wall top and bottom pixels on the screen
        wall_top_pixel = get_top_pixel(game, wall_strip_height);
        wall_bottom_pixel = get_bottom_pixel(game, wall_strip_height);

        // Select the correct texture based on wall hit direction
        if (rays[i].was_hit_vertical)
        {
            if (rays[i].is_ray_facing_right)
                texture = game->ea_texture;
            else
                texture = game->we_texture;
        }
        else
        {
            if (rays[i].is_ray_facing_down)
                texture = game->so_texture;
            else
                texture = game->no_texture;
        }

        // Get the x-coordinate in the texture
        tex_x = get_texture_x(&rays[i], texture, TILE_SIZE);

        // Draw the wall strip
        for (int y = wall_top_pixel; y < wall_bottom_pixel; y++)
        {
            // Map the current screen y-coordinate to the texture y-coordinate
            tex_y = (int)(((y - wall_top_pixel) / (double)wall_strip_height) * texture->height);

            // Get the color from the texture
            uint8_t r = texture->pixels[(tex_y * texture->width + tex_x) * 4 + 0];
            uint8_t g = texture->pixels[(tex_y * texture->width + tex_x) * 4 + 1];
            uint8_t b = texture->pixels[(tex_y * texture->width + tex_x) * 4 + 2];
            uint8_t a = texture->pixels[(tex_y * texture->width + tex_x) * 4 + 3]; // Alpha channel

            color = (r << 24) | (g << 16) | (b << 8) | a;

            // Draw the pixel to the screen
            ft_put_pixel(game->img, i, y, color);
        }
    }
}
