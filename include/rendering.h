/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:05:39 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/16 20:02:49 by bbelarra42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MLX42/MLX42.h>
#include <cub3D.h>

typedef struct s_render
{
	int				i;
	int				y;
	double			perp_distance;
	double			distance_proj_plane;
	double			proj_wall_height;
	int				wall_strip_height;
	int				wall_top_pixel;
	int				wall_bottom_pixel;
	int				color;
	mlx_texture_t	*texture;
	int				r;
	int				g;
	int				b;
	int				a;
	int				tex_x;
	int				tex_y;
}					t_render;

void	put_get_color(t_render *render, t_game *game);