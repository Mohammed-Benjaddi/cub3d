/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:15:47 by bbelarra          #+#    #+#             */
/*   Updated: 2025/01/12 03:40:10 by bbelarra42       ###   ########.fr       */
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

int	failure_help(t_parse *map_info, t_syn *syn)
{
	if (map_info->map[syn->i][syn->y] == 'C')
	{
		syn->continues = ceil_check(map_info, syn->i, &syn->c);
		return (1);
	}
	if (map_info->map[syn->i][syn->y] == 'F')
	{
		syn->continues = floor_check(map_info, syn->i, &syn->f);
		return (1);
	}
	else if (map_info->map[syn->i][syn->y] != ' '
		&& map_info->map[syn->i][syn->y] != 'N'
		&& map_info->map[syn->i][syn->y] != 'S'
		&& map_info->map[syn->i][syn->y] != 'W'
		&& map_info->map[syn->i][syn->y] != 'E'
		&& map_info->map[syn->i][syn->y] != 'C'
		&& map_info->map[syn->i][syn->y] != 'F'
		&& map_info->map[syn->i][syn->y] != '\n')
		return (-1);
	return (1);
}

int	failure_check(t_parse *map_info, t_syn *syn)
{
	if (map_info->map[syn->i][syn->y] == 'N')
	{
		syn->continues = north_checker(map_info, syn->i, &syn->n);
		return (1);
	}
	else if (map_info->map[syn->i][syn->y] == 'S')
	{
		syn->continues = south_checker(map_info, syn->i, &syn->s);
		return (1);
	}
	else if (map_info->map[syn->i][syn->y] == 'W')
	{
		syn->continues = west_checker(map_info, syn->i, &syn->w);
		return (1);
	}
	else if (map_info->map[syn->i][syn->y] == 'E')
	{
		syn->continues = east_checker(map_info, syn->i, &syn->e);
		return (1);
	}
	return (failure_help(map_info, syn));
}

int	syntaxer(t_parse *map_info)
{
	t_syn	syn;

	init_syn(&syn);
	while (syn.i < map_info->som)
	{
		syn.y = 0;
		while (map_info->map[syn.i][syn.y]
			&& map_info->map[syn.i][syn.y] != '\n')
		{
			if (failure_check(map_info, &syn) == 1)
				break ;
			if (failure_check(map_info, &syn) == -1)
				return (1);
			syn.y++;
		}
		if (syn.continues == -1)
			return (1);
		syn.i++;
	}
	if (syn.s != 1 || syn.n != 1 || syn.e != 1 || syn.w != 1 || syn.c != 1
		|| syn.f != 1)
		return (1);
	texture_initilizer(map_info);
	return (0);
}
