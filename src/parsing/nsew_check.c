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

#include "../../include/parsing.h"

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
			{
				if (map_info->map[i][y + 1] != 'O' || map_info->map[i][y
					+ 2] != ' ')
					return (-1);
				if (count_word(map_info->map[i], ' ') != 2)
					return (-1);
				continues = i + 1;
				return (continues);
			}
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
			{
				if (map_info->map[i][y + 1] != 'O' || map_info->map[i][y
					+ 2] != ' ')
					return (-1);
				if (count_word(map_info->map[i], ' ') != 2)
					return (-1);
				continues = i + 1;
				return (continues);
			}
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
			{
				if (map_info->map[i][y + 1] != 'A' || map_info->map[i][y
					+ 2] != ' ')
					return (-1);
				if (count_word(map_info->map[i], ' ') != 2)
					return (-1);
				continues = i + 1;
				return (continues);
			}
			y++;
		}
		i++;
	}
	return (-1);
}

int	color_syntax(t_parse *map_info, char *line, int color)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (color == 0)
	{
		if (line[i] != 'C')
			exit(1);
	}
	else if (color == 1)
	{
		if (line[i] != 'F')
			return (1);
	}
	i++;
	while (line[i] == ' ')
		i++;
	r = 0;
	if (!ft_isdigit(line[i]))
		return (1);
	while (ft_isdigit(line[i]))
	{
		r = r * 10 + (line[i] - '0');
		i++;
	}
	if (r < 0 || r > 255)
		return (1);
	while (line[i] == ' ')
		i++;
	if (line[i] != ',')
		return (1);
	i++;
	g = 0;
	if (!ft_isdigit(line[i]))
		return (1);
	while (ft_isdigit(line[i]))
	{
		g = g * 10 + (line[i] - '0');
		i++;
	}
	if (g < 0 || g > 255)
		return (1);
	while (line[i] == ' ')
		i++;
	if (line[i] != ',')
		return (1);
	i++;
	b = 0;
	if (!ft_isdigit(line[i]))
		return (1);
	while (ft_isdigit(line[i]))
	{
		b = b * 10 + (line[i] - '0');
		i++;
	}
	if (b < 0 || b > 255)
		return (1);
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0' && line[i] != '\n')
		return (1);
	if (color == 0)
		map_info->ceiling_color = r << 24 | g << 16 | b << 8 | 0xFF;
	else if (color == 1)
		map_info->floor_color = r << 24 | g << 16 | b << 8 | 0xFF;
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
			{
				if (map_info->map[i][y + 1] != ' ')
					return (-1);
				if (count_word(map_info->map[i], ' ') != 2
					|| color_syntax(map_info, map_info->map[i], 0))
					return (-1);
				continues = i + 1;
				return (continues);
			}
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
			{
				if (map_info->map[i][y + 1] != ' ')
					return (-1);
				if (count_word(map_info->map[i], ' ') != 2
					|| color_syntax(map_info, map_info->map[i], 1))
					return (-1);
				continues = i + 1;
				return (continues);
			}
			y++;
		}
		i++;
	}
	return (-1);
}

int	west_checker(t_parse *map_info, int continues, int *W)
{
	int i = continues;
	int y = 0;
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
			{
				if (map_info->map[i][y + 1] != 'E' || map_info->map[i][y
					+ 2] != ' ')
					return (-1);
				if (count_word(map_info->map[i], ' ') != 2)
					return (-1);
				continues = i + 1;
				return (continues);
			}
			y++;
		}
		i++;
	}
	return (-1);
}
