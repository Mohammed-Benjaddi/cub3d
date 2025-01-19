/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:25:44 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/19 16:11:30 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

size_t	get_longest_line(t_parse *map_info)
{
	int		i;
	size_t	current;
	size_t	new;

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

int	set_height_width(t_parse *map_info)
{
	size_t	height;

	height = 0;
	while (map_info->original[height])
		height++;
	map_info->height = height;
	map_info->width = get_longest_line(map_info);
	return (0);
}

void	overwrite(char *line)
{
	int	size;
	int	save;
	int	flager;

	flager = 0;
	size = custom_strlen(line);
	save = size;
	size--;
	while (line[size] == ' ')
	{
		flager = 1;
		size--;
	}
	if (flager == 1)
	{
		size++;
		line[size] = line[save];
	}
}

void	trim_empty(char **original)
{
	int	i;

	i = 0;
	while (original[i])
	{
		overwrite(original[i]);
		i++;
	}
}
