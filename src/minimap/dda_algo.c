/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:16:51 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/19 00:31:23 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_dda_algo	init_dda(t_minimap *minimap, double rot_angle)
{
	t_dda_algo	dda;

	dda.n_px = minimap->h + cos(rot_angle) * (TILE_SIZE / 2);
	dda.n_py = minimap->v + sin(rot_angle) * (TILE_SIZE / 2);
	dda.dx = dda.n_px - minimap->h;
	dda.dy = dda.n_py - minimap->v;
	if (fabs(dda.dx) > fabs(dda.dy))
		dda.steps = fabs(dda.dx);
	else
		dda.steps = fabs(dda.dy);
	dda.x = minimap->h;
	dda.y = minimap->v;
	dda.x_inc = dda.dx / dda.steps;
	dda.y_inc = dda.dy / dda.steps;
	return (dda);
}

void	dda(t_minimap *minimap, double rot_angle)
{
	t_dda_algo	dda;
	int			i;

	i = 0;
	dda = init_dda(minimap, rot_angle);
	while (i <= dda.steps)
	{
		ft_put_pixel(minimap->mm_img, roundf(dda.x), roundf(dda.y), RED);
		dda.x += dda.x_inc;
		dda.y += dda.y_inc;
		i++;
	}
}
