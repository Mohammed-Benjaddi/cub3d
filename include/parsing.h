/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:32:49 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/13 09:29:18 by bbelarra42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "get_next_line.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_rgb
{
	int		i;
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct s_syn
{
	int		i;
	int		y;
	int		f;
	int		c;
	int		n;
	int		s;
	int		w;
	int		e;
	int		continues;
}			t_syn;

typedef struct s_parse
{
	int		ceiling_color;
	int		floor_color;
	int		fd;
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;

	size_t	som;
	size_t	map_size;

	int		player_x;
	int		player_y;

	char	**original;
	size_t	width;
	size_t	height;
}			t_parse;

void		print_original(t_parse *map_info);

int			north_checker(t_parse *map_info, int continues, int *N);
int			south_checker(t_parse *map_info, int continues, int *S);
int			west_checker(t_parse *map_info, int continues, int *W);
int			east_checker(t_parse *map_info, int continues, int *E);
size_t		real_size(t_parse *map_info);
char		**set_original(char **src, size_t size, int som);
void		free_original(char **map);
void		set_height_width(t_parse *map_info);
size_t		get_longest_line(t_parse *map_info);
void		overwrite(char *line);
int			valid(char *line);
void		trim_empty(char **original);
void		texture_initilizer(t_parse *map_info);
void		init_syn(t_syn *syn);
int			failure_check(t_parse *map_info, t_syn *syn);
int			failure_help(t_parse *map_info, t_syn *syn);
int			color_syntax(t_parse *map_info, char *line, int color);
int			position_helper(t_parse *map_info, int *found, int *i, int *y);
int			floor_check(t_parse *map_info, int continues, int *F);
int			ceil_check(t_parse *map_info, int continues, int *C);
int			map_checker(char **map, int len);
int			ns_help(t_parse *map_info, int i, int y, int continues);
int			w_help(t_parse *map_info, int i, int y, int continues);
int			e_help(t_parse *map_info, int i, int y, int continues);
void		map_start(t_parse *map_info);
int			position_finder(t_parse *map_info);
int			floor_help(t_parse *map_info, int i, int y, int continues);
int			ceil_help(t_parse *map_info, int i, int y, int continues);

int			r(t_parse *map_info, t_rgb *rgb, char *line, int color);
int			g(t_parse *map_info, t_rgb *rgb, char *line, int color);
int			b(t_parse *map_info, t_rgb *rgb, char *line, int color);
void		rgb_init(t_rgb *rgb);

char		*norther(char **map);
char		*easter(char **map);
char		*wester(char **map);
char		*souther(char **map);

char		*texture_cuter(char *string);
size_t		count_word(char *string, char delimiter);
size_t		size_calc(int fd);
size_t		custom_strlen(char *string);
int			syntaxer(t_parse *map_info);
int			structer(char **map, int stop);
void		map_free(t_parse *map_info);
void		parse_free(t_parse *map_info);

void		flood_fill(char **map, int i, int y);
int			parse_entry(t_parse *map_info, int ac, char **av);
void		flood_filler(t_parse *map_info);
#endif
