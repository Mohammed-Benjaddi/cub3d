/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nsew_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:15:47 by bbelarra          #+#    #+#             */
/*   Updated: 2025/01/17 22:07:17 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing_bonus.h"

int	south_checker(t_parse *map_info, int continues, int *S)
{
	int	i;
	int	y;

	i = continues;
	y = 0;
	if ((*S != 0))
		return (-1);
	(*S) = 1;
	while (map_info->map[i])
	{
		y = 0;
		while (map_info->map[i][y] && map_info->map[i][y] != '\n')
		{
			if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'S')
				return (-1);
			if (map_info->map[i][y] == 'S')
				return (ns_help(map_info, i, y, continues));
			y++;
		}
		i++;
	}
	return (-1);
}

int	north_checker(t_parse *map_info, int continues, int *N)
{
	int	i;
	int	y;

	i = continues;
	y = 0;
	if ((*N != 0))
		return (-1);
	(*N) = 1;
	while (map_info->map[i])
	{
		y = 0;
		while (map_info->map[i][y] && map_info->map[i][y] != '\n')
		{
			if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'N')
				return (-1);
			if (map_info->map[i][y] == 'N')
				return (ns_help(map_info, i, y, continues));
			y++;
		}
		i++;
	}
	return (-1);
}

int	east_checker(t_parse *map_info, int continues, int *E)
{
	int	i;
	int	y;

	i = continues;
	y = 0;
	if ((*E != 0))
		return (-1);
	(*E) = 1;
	while (map_info->map[i])
	{
		y = 0;
		while (map_info->map[i][y] && map_info->map[i][y] != '\n')
		{
			if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'E')
				return (-1);
			if (map_info->map[i][y] == 'E')
				return (e_help(map_info, i, y, continues));
			y++;
		}
		i++;
	}
	return (-1);
}

int	west_checker(t_parse *map_info, int continues, int *W)
{
	int	i;
	int	y;

	i = continues;
	y = 0;
	if ((*W != 0))
		return (-1);
	(*W) = 1;
	while (map_info->map[i])
	{
		y = 0;
		while (map_info->map[i][y] && map_info->map[i][y] != '\n')
		{
			if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'W')
				return (-1);
			if (map_info->map[i][y] == 'W')
				return (w_help(map_info, i, y, continues));
			y++;
		}
		i++;
	}
	return (-1);
}

int	color_syntax(t_parse *map_info, char *line, int color)
{
	t_rgb	rgb;

	rgb_init(&rgb);
	if (r(&rgb, line, color))
		return (1);
	if (g(&rgb, line))
		return (1);
	if (b(&rgb, line))
		return (1);
	if (line[rgb.i] != '\0' && line[rgb.i] != '\n' && line[rgb.i] != ' ')
		return (1);
	if (color == 0)
		map_info->ceiling_color = rgb.r << 24 | rgb.g << 16 | rgb.b << 8 | 0xFF;
	else if (color == 1)
		map_info->floor_color = rgb.r << 24 | rgb.g << 16 | rgb.b << 8 | 0xFF;
	return (0);
}
