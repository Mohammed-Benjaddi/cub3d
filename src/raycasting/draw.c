/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:01:26 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/15 21:16:01 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_pixel(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			ft_put_pixel(game->img, x + j, y + i, BLACK);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (!game->map)
		perror("Error: map not found\n");
	// draw_background(game);
	game->img = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
		perror("putting image to window failed");
	// while (game->map[i])
	// {
	// 	j = 0;
	// 	while (game->map[i][j])
	// 	{
	// 		if (game->map[i][j] == '1')
	// 			ft_pixel(game, j * TILE_SIZE, i * TILE_SIZE);
	// 		j++;
	// 	}
	// 	i++;
	// }
}

void	ft_put_pixel(mlx_image_t *image, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= (int)image->width || y >= (int)image->height)
		return ;
	mlx_put_pixel(image, x, y, color);
}

void	draw_background(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->background = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->background || (mlx_image_to_window(game->mlx, game->background,
				0, 0)) < 0)
		perror("putting image to window failed");
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			ft_put_pixel(game->background, i, j, WHITE);
			j++;
		}
		i++;
	}
}
