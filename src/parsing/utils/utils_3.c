/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:15:47 by bbelarra          #+#    #+#             */
/*   Updated: 2025/01/16 22:01:36 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

void	map_free(t_parse *map_info)
{
	int	i;

	i = 0;
	while (map_info->map[i])
	{
		free(map_info->map[i]);
		i++;
	}
	free(map_info->map[i]);
	free(map_info->map);
}

int	map_checker(char **map, int len)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y] && map[i][y] != '\n')
		{
			if ((map[i][y] == 'M') && (i == 0 || y == 0 || i == len))
				return (1);
			else if (check_help(map, i, y))
				return (1);
			else if ((i + 1 < len && map[i][y] == 'M')
				&& ((int)custom_strlen(map[i + 1]) - 1 < y || map[i
					+ 1][y] == ' '))
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

int	position_helper(t_parse *map_info, int *found, int *i, int *y)
{
	if (map_info->map[(*i)][(*y)] != ' ' && map_info->map[(*i)][(*y)] != 'N'
		&& map_info->map[(*i)][(*y)] != 'S' && map_info->map[(*i)][(*y)] != 'E'
		&& map_info->map[(*i)][(*y)] != 'W' && map_info->map[(*i)][(*y)] != '0'
		&& map_info->map[(*i)][(*y)] != '1')
		return (1);
	if (map_info->map[(*i)][(*y)] == 'W' || map_info->map[(*i)][(*y)] == 'S'
		|| map_info->map[(*i)][(*y)] == 'N' || map_info->map[(*i)][(*y)] == 'E')
	{
		map_info->player_x = (*y);
		map_info->player_y = (*i) - map_info->som;
		(*found)++;
	}
	return (0);
}

int	ceil_check(t_parse *map_info, int continues, int *C)
{
	int	i;
	int	y;

	i = continues;
	y = 0;
	if ((*C != 0))
		return (-1);
	(*C) = 1;
	while (map_info->map[i])
	{
		y = 0;
		while (map_info->map[i][y] && map_info->map[i][y] != '\n')
		{
			if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'C')
				return (-1);
			if (map_info->map[i][y] == 'C')
				return (ceil_help(map_info, i, y, continues));
			y++;
		}
		i++;
	}
	return (-1);
}

int	floor_check(t_parse *map_info, int continues, int *F)
{
	int	i;
	int	y;

	i = continues;
	y = 0;
	if ((*F != 0))
		return (-1);
	(*F) = 1;
	while (map_info->map[i])
	{
		y = 0;
		while (map_info->map[i][y] && map_info->map[i][y] != '\n')
		{
			if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'F')
				return (-1);
			if (map_info->map[i][y] == 'F')
				return (floor_help(map_info, i, y, continues));
			y++;
		}
		i++;
	}
	return (-1);
}
