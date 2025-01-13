/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:25:44 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/13 09:26:59 by bbelarra42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

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

void	set_height_width(t_parse *map_info)
{
	size_t	height;

	height = 0;
	while (map_info->original[height])
		height++;
	map_info->height = height;
	map_info->width = get_longest_line(map_info);
}
