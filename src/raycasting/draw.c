/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:01:26 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/17 22:09:01 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

void	draw_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		perror("Error: map not found\n");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img || (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0))
		perror("putting image to window failed");
}

void	ft_put_pixel(mlx_image_t *image, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	mlx_put_pixel(image, x, y, color);
}
