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
	free(map_info->SO_TEXTURE);
	free(map_info->NO_TEXTURE);
	free(map_info->EA_TEXTURE);
	free(map_info->WE_TEXTURE);
	close(map_info->fd);
}

void	flood_fill(char **map, int i, int y)
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

void	print_map(char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

int	name_checker(char *map_name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'b' || map_name[len - 2] != 'u' || map_name[len
		- 3] != 'c' || map_name[len - 4] != '.')
		return (1);
	return (0);
}
