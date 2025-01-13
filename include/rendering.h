/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:05:39 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/13 06:44:23 by bbelarra42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>

typedef struct s_render
{
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
}					t_render;