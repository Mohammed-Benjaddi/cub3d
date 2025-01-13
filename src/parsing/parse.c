/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 03:42:44 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/13 09:11:50 by bbelarra42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

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

void	print_original(t_parse *map_info)
{
	int	i;

	i = 0;
	printf("------------------------- MAP ---------------------------\n");
	while (map_info->original[i])
	{
		printf("%s\n", map_info->original[i]);
		i++;
	}
	printf("---------------------------------------------------------\n");
	printf("\n\n\n---------------- CORD -----------------------------\n");
	printf("x: %d, y: %d \n", map_info->player_x, map_info->player_y);
	printf("---------------------------------------------------------\n");
	printf("\n\n\n---------------- HEIGHT AND WIDTH -----------------\n");
	printf("width: %zu, height: %zu \n", map_info->width, map_info->height);
	printf("---------------------------------------------------------\n");
}

size_t	real_size(t_parse *map_info)
{
	size_t	i;
	size_t	real_size;

	real_size = 0;
	i = map_info->som;
	while (map_info->map[i] && valid(map_info->map[i]))
	{
		real_size++;
		i++;
	}
	return (real_size);
}

t_parse	*map_setter(t_parse *map_info, int ac, char **av)
{
	char	*line;
	int		i;

	i = -1;
	map_info->som = 0;
	map_info->map_size = size_calc(map_info->fd);
	map_info->fd = open(av[1], O_RDONLY);
	map_info->map = (char **)malloc(sizeof(char *) * (map_info->map_size + 1));
	while (++i < map_info->map_size)
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

size_t	get_longest_line(t_parse *map_info)
{
	int		i;
	size_t	current;
	int		new;

	i = 0;
	current = 0;
	while (map_info->original[i])
	{
		new = cus_strlen(map_info->original[i]);
		if (new > current)
			current = cus_strlen(map_info->original[i]);
		i++;
	}
	return (current);
}

void	set_height_width(t_parse *map_info)
{
	size_t	height;

	height = 0;
	while (map_info->original[height])
		height++;
	map_info->height = height;
	map_info->width = get_longest_line(map_info);
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
	if (!map_setter(map_info, ac, av))
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
	set_height_width(map_info);
	print_original(map_info);
	return (1);
}
