/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:15:47 by bbelarra          #+#    #+#             */
/*   Updated: 2024/12/06 04:54:40 by bbelarra42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	where(char *string)
{
	int	i;

	i = 0;
	while (string[i] && string[i] != '\n' && string[i] != ' ')
		i++;
	return (i);
}

char	*texture_cuter(char *string)
{
	int		i;
	int		start;
	int		index;
	char	*no_texture;

	i = 0;
	start = 0;
	while (string[start] == ' ')
		start++;
	index = where(&string[start]);
	no_texture = ft_substr(string, start, index);
	return (no_texture);
}

int	syntaxer(t_parse *map_info)
{
	int	i;
	int	y;
	int	f;
	int	c;
	int	n;
	int	s;
	int	w;
	int	e;
	int	continues;

	i = 0;
	y = 0;
	f = 0;
	c = 0;
	n = 0;
	s = 0;
	w = 0;
	w = 0;
	continues = 0;
	while (i < map_info->som)
	{
		y = 0;
		while (map_info->map[i][y] && map_info->map[i][y] != '\n')
		{
			if (map_info->map[i][y] == 'N')
			{
				continues = north_checker(map_info, i, &N);
				break ;
			}
			else if (map_info->map[i][y] == 'S')
			{
				continues = south_checker(map_info, i, &S);
				break ;
			}
			else if (map_info->map[i][y] == 'W')
			{
				continues = west_checker(map_info, i, &W);
				break ;
			}
			else if (map_info->map[i][y] == 'E')
			{
				continues = east_checker(map_info, i, &E);
				break ;
			}
			else if (map_info->map[i][y] == 'C')
			{
				continues = ceil_check(map_info, i, &C);
				break ;
			}
			else if (map_info->map[i][y] == 'F')
			{
				continues = floor_check(map_info, i, &F);
				break ;
			}
			else if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'N'
				&& map_info->map[i][y] != 'S' && map_info->map[i][y] != 'W'
				&& map_info->map[i][y] != 'E' && map_info->map[i][y] != 'C'
				&& map_info->map[i][y] != 'F' && map_info->map[i][y] != '\n')
				return (map_free(map_info), 1);
			y++;
		}
		if (continues == -1)
			return (map_free(map_info), 1);
		i++;
	}
	if (s != 1 || n != 1 || e != 1 || w != 1 || c != 1 || f != 1)
		return (map_free(map_info), 1);
	map_info->NO_TEXTURE = norther(map_info->map);
	map_info->SO_TEXTURE = souther(map_info->map);
	map_info->WE_TEXTURE = wester(map_info->map);
	map_info->EA_TEXTURE = easter(map_info->map);
	return (0);
}
