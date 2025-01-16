/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:55:29 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/16 12:05:32 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_minimap(t_game *game, t_minimap *minimap)
{
	minimap->x = game->player.player_x / 2;
	minimap->y = game->player.player_y / 2;
	minimap->h = 6 * (TILE_SIZE / 2);
	minimap->v = 4 * (TILE_SIZE / 2);
	minimap->width = minimap->h * 2;
	minimap->height = minimap->v * 2;
	minimap->mm_img = mlx_new_image(game->mlx, minimap->width, minimap->height);
	if (!minimap->mm_img || (mlx_image_to_window(game->mlx, minimap->mm_img, 10,
				10)) < 0)
		perror("putting image to window failed");
}

void	minimap_put_pixel(t_game *game, t_minimap *minimap, uint32_t color)
{
	if (minimap->s_x - (minimap->x - minimap->h) < 0 || minimap->s_y
		- (minimap->y - minimap->v) < 0 || minimap->s_x - (minimap->x
			- minimap->h) >= minimap->width || minimap->s_y - (minimap->y
			- minimap->v) >= minimap->height)
		return ;
	mlx_put_pixel(minimap->mm_img, minimap->s_x - (minimap->x - minimap->h),
		minimap->s_y - (minimap->y - minimap->v), color);
}

void	put_player_minimap(t_game *game, t_minimap *minimap)
{
	int	i;
	int	j;

	i = -3;
	while (i < 3)
	{
		j = -3;
		while (j < 3)
		{
			mlx_put_pixel(minimap->mm_img, minimap->h + j, minimap->v + i, RED);
			j++;
		}
		i++;
	}
	dda(minimap, game->player.rotation_angle);
}

void	draw_minimap_pix(t_game *game, t_minimap *minimap)
{
	if ((minimap->s_x / (TILE_SIZE / 2)) >= 0 && (minimap->s_y / (TILE_SIZE
				/ 2)) >= 0 && (minimap->s_y / (TILE_SIZE / 2)) < game->map_info->height
		&& (minimap->s_x / (TILE_SIZE
				/ 2)) < (int)ft_strlen(game->map[(int)(minimap->s_y / (TILE_SIZE
					/ 2))]) && game->map[(int)(minimap->s_y / (TILE_SIZE
				/ 2))][(int)(minimap->s_x / (TILE_SIZE / 2))] == '1')
		minimap_put_pixel(game, minimap, BLACK);
	else
		minimap_put_pixel(game, minimap, WHITE);
}

void	draw_minimap(t_game *game)
{
	t_minimap	*minimap;

	minimap = game->minimap;
	init_minimap(game, minimap);
	minimap->s_y = minimap->y - minimap->v;
	minimap->end_y = minimap->y + minimap->v;
	while (minimap->s_y < minimap->end_y)
	{
		minimap->s_x = minimap->x - minimap->h;
		minimap->end_x = minimap->x + minimap->h;
		while (minimap->s_x < minimap->end_x)
		{
			draw_minimap_pix(game, minimap);
			put_player_minimap(game, minimap);
			minimap->s_x++;
		}
		minimap->s_y++;
	}
}
