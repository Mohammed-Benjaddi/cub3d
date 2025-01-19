/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:15:47 by bbelarra          #+#    #+#             */
/*   Updated: 2025/01/19 16:09:45 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	valid(char *line)
{
	int	i;

	i = 0;
	if (line[i] && line[i] != '\n')
		return (1);
	return (0);
}

size_t	size_calc(int fd)
{
	char	*line;
	size_t	map_size;

	map_size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		map_size++;
	}
	close(fd);
	return (map_size);
}

void	parse_free(t_parse *map_info)
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
	free(map_info->so_texture);
	free(map_info->no_texture);
	free(map_info->ea_texture);
	free(map_info->we_texture);
	free_original(map_info->original);
	close(map_info->fd);
}

void	flood_fill(char **map, int i, size_t y)
{
	if (!map[i] || !map[i][y] || map[i][y] == ' ' || map[i][y] == '1'
		|| map[i][y] == '\n' || map[i][y] == 'M')
	{
		return ;
	}
	map[i][y] = 'M';
	if (!map[i + 1] || custom_strlen(map[i + 1]) - 1 > y)
		flood_fill(map, i + 1, y);
	if (i != 0 && custom_strlen(map[i - 1]) - 1 > y)
		flood_fill(map, i - 1, y);
	flood_fill(map, i, y + 1);
	if (y != 0)
		flood_fill(map, i, y - 1);
}

int	name_checker(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'b' || map_name[len - 2] != 'u' || map_name[len
			- 3] != 'c' || map_name[len - 4] != '.')
		return (1);
	return (0);
}
