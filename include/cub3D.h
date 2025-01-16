/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:48:07 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/16 18:58:29 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define RED 0xFF0000FF
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF
# define GREEN 0x00cb12
# define BLUE 0x006cff
# define CYAN 0x00ffec
# define BEIGE 0xFFB38E

# define PI 3.14159265358979323846
// # define fov 60 * PI / 180
# define NUM_RAYS 1200
# define TILE_SIZE 30
# define MM_TILE_SIZE 20

# include "parsing.h"
# include <MLX42/MLX42.h>
# include <libft.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_dda_algo
{
	int					n_px;
	int					n_py;
	double				dx;
	double				dy;
	double				steps;
	double				x;
	double				y;
	double				x_inc;
	double				y_inc;
}						t_dda_algo;

typedef struct s_hor_intersection
{
	bool				found_horz_wall_hit;
	double				next_horz_touch_x;
	double				next_horz_touch_y;
	double				horz_wall_hit_x;
	double				horz_wall_hit_y;
	double				xintercept;
	double				yintercept;
	double				xstep;
	double				ystep;
	double				x_check;
	double				y_check;
}						t_hor_intersection;

typedef struct s_ver_intersection
{
	bool				found_vert_wall_hit;
	double				next_vert_touch_x;
	double				next_vert_touch_y;
	double				vert_wall_hit_x;
	double				vert_wall_hit_y;
	double				xintercept;
	double				yintercept;
	double				xstep;
	double				ystep;
	double				x_check;
	double				y_check;
}						t_ver_intersection;

typedef struct s_ray
{
	double				ray_angle;
	double				wall_hit_x;
	double				wall_hit_y;
	double				distance;
	int					was_hit_vertical;
	int					is_ray_facing_up;
	int					is_ray_facing_down;
	int					is_ray_facing_left;
	int					is_ray_facing_right;
}						t_ray;

typedef struct s_player
{
	double				player_x;
	double				player_y;
	double				n_px;
	double				n_py;
	double				rotation_speed;
	int					turn_direction;
	double				rotation_angle;
	int					walk_direction;
	double				move_speed;
	double				move_step;
}						t_player;

typedef struct s_minimap
{
	int					v;
	int					h;
	int					width;
	int					height;
	double				x;
	double				y;
	double				s_y;
	double				s_x;
	double				end_x;
	double				end_y;
	mlx_image_t			*mm_img;
}						t_minimap;

typedef struct s_game
{
	int					width;
	int					height;
	int					num_rays;
	double				fov;
	char				**map;
	mlx_t				*mlx;
	mlx_image_t			*img;
	mlx_image_t			*background;
	t_player			player;
	t_hor_intersection	h_intersection;
	t_ver_intersection	v_intersection;
	t_ray				*rays;
	t_minimap			*minimap;
	t_parse				*map_info;
	mlx_texture_t		*no_texture;
	mlx_texture_t		*so_texture;
	mlx_texture_t		*we_texture;
	mlx_texture_t		*ea_texture;
}						t_game;

void					raycarting(t_game *game);
double					deg_to_rad(double deg);
double					rad_to_deg(double rad);
double					get_new_x(t_game *game, double angle);
double					get_new_y(t_game *game, double angle);
void					rebuild_map(t_game *game);
void					set_player_position(t_game *game);
void					draw_map(t_game *game);
void					draw_background(t_game *game);
void					ft_put_pixel(mlx_image_t *image, int x, int y,
							int color);
void					put_player(t_game *game);
void					cast_rays(t_game *game);
void					horizontal_intersection(t_game *game,
							t_hor_intersection *hor_inter, double ray_angle);
void					vertical_intersection(t_game *game,
							t_ver_intersection *ver_inter, double ray_angle);
int						is_ray_facing_down(double ray_angle);
int						is_ray_facing_up(double ray_angle);
int						is_ray_facing_right(double ray_angle);
int						is_ray_facing_left(double ray_angle);
bool					is_player(char c);
void					right_arrow(t_game *game);
void					left_arrow(t_game *game);
void					w_key(t_game *game);
void					s_key(t_game *game);
void					d_key(t_game *game);
void					a_key(t_game *game);
void					render_walls(t_game *game, t_ray *rays);
void					draw_minimap(t_game *game);
void					init_minimap(t_game *game, t_minimap *minimap);
bool					player_can_move(t_game *game, double new_x,
							double new_y);
void					get_first_hor_inter(t_game *game,
							t_hor_intersection *hor_inter, double ray_angle);
void					get_first_ver_inter(t_game *game,
							t_ver_intersection *ver_inter, double ray_angle);
bool					map_has_wall(t_game *game, double x, double y);
void					dda(t_minimap *minimap, double rot_angle);
void					ft_hook(mlx_key_data_t keydata, void *param);
t_game				*init_infos(t_parse *parse);

#endif
