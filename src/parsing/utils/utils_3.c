/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:15:47 by bbelarra          #+#    #+#             */
/*   Updated: 2025/01/12 04:01:45 by bbelarra42       ###   ########.fr       */
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
			else if (map[i][y] == 'M' && (map[i][y + 1] == '\n' || map[i][y
					+ 1] == ' ' || map[i][y - 1] == ' ' || custom_strlen(map[i
						- 1]) - 1 < y || custom_strlen(map[i + 1]) - 1 < y
					|| map[i + 1][y] == ' ' || map[i - 1][y] == ' '))
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
		map_info->player_y = (*i);
		(*found)++;
	}
	return (0);
}
