/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:42:44 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/17 22:07:17 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

int	position_finder(t_parse *map_info)
{
	int	i;
	int	y;
	int	found;

	i = map_info->som;
	y = 0;
	found = 0;
	while (map_info->map[i])
	{
		y = 0;
		while (map_info->map[i][y] && map_info->map[i][y] != '\n')
		{
			if (position_helper(map_info, &found, &i, &y))
				return (1);
			y++;
		}
		i++;
	}
	if (found != 1)
		return (1);
	return (0);
}

t_parse	*map_setter(t_parse *map_info, char **av)
{
	int	i;

	i = -1;
	map_info->som = 0;
	map_info->map_size = size_calc(map_info->fd);
	map_info->fd = open(av[1], O_RDONLY);
	map_info->map = (char **)malloc(sizeof(char *) * (map_info->map_size + 1));
	while (++i < (int)map_info->map_size)
		map_info->map[i] = get_next_line(map_info->fd);
	map_info->map[i] = NULL;
	map_start(map_info);
	map_info->original = set_original(map_info->map, map_info->map_size
			- map_info->som, map_info->som);
	if (position_finder(map_info))
		return (NULL);
	map_info->map_size = real_size(map_info);
	return (map_info);
}

void	map_start(t_parse *map_info)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map_info->map[i])
	{
		y = 0;
		while (map_info->map[i][y] && map_info->map[i][y] != '\n')
		{
			if (map_info->map[i][y] == 'N' || map_info->map[i][y] == 'S'
				|| map_info->map[i][y] == 'E' || map_info->map[i][y] == 'W'
				|| map_info->map[i][y] == 'C' || map_info->map[i][y] == 'F')
				break ;
			else if (map_info->map[i][y] == '0' || map_info->map[i][y] == '1')
				map_info->som = i;
			y++;
		}
		if (map_info->som != 0)
			break ;
		i++;
	}
	return ;
}

void	flood_filler(t_parse *map_info)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	i = map_info->som;
	while (map_info->map[i])
	{
		y = 0;
		while (map_info->map[i][y] && map_info->map[i][y] != '\n')
		{
			if (map_info->map[i][y] == '0')
				flood_fill(map_info->map, i, y);
			y++;
		}
		i++;
	}
}

int	parse_entry(t_parse *map_info, int ac, char **av)
{
	if (ac != 2)
		return (write(2, "Error\ninvalid number of arguments\n", 34), 0);
	map_info->fd = open(av[1], O_RDONLY);
	if (map_info->fd == -1)
		return (write(2, "Error\nFailed to open file\n", 26), 0);
	if (name_checker(av[1]))
		return (close(map_info->fd), write(2, "Error\nInvalid map name\n", 23),
			0);
	if (!map_setter(map_info, av))
		return (map_free(map_info), free_original(map_info->original), write(2,
				"Error\nCheck your map content\n", 29), 0);
	flood_filler(map_info);
	if (map_checker(&map_info->map[map_info->som], map_info->map_size - 1))
		return (map_free(map_info), free_original(map_info->original),
			close(map_info->fd), write(2, "Error\nCheck your map content\n",
				29), 0);
	if (syntaxer(map_info))
		return (map_free(map_info), free_original(map_info->original),
			close(map_info->fd), write(2, "Error\nCheck your map content\n",
				29), 0);
	trim_empty(map_info->original);
	set_height_width(map_info);
	return (1);
}
