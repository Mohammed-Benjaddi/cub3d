/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:15:47 by bbelarra          #+#    #+#             */
/*   Updated: 2025/01/13 09:07:55 by bbelarra42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

char	*norther(char **map)
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
			if (map[i][y] == 'N')
				return (texture_cuter(&map[i][y + 3]));
			if (map[i][y] != ' ' && map[i][y] != 'N')
				break ;
			y++;
		}
		i++;
	}
	return (NULL);
}

char	*souther(char **map)
{
	int	i;
	int	y;
	int	flager;

	i = 0;
	y = 0;
	flager = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y] && map[i][y] != '\n')
		{
			if (map[i][y] == 'S')
				return (texture_cuter(&map[i][y + 3]));
			if (map[i][y] != ' ' && map[i][y] != 'S')
				break ;
			y++;
		}
		i++;
	}
	return (NULL);
}

char	*wester(char **map)
{
	int	i;
	int	y;
	int	flager;

	i = 0;
	y = 0;
	flager = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y] && map[i][y] != '\n')
		{
			if (map[i][y] == 'W')
				return (texture_cuter(&map[i][y + 3]));
			if (map[i][y] != ' ' && map[i][y] != 'W')
				break ;
			y++;
		}
		i++;
	}
	return (NULL);
}

char	*easter(char **map)
{
	int	i;
	int	y;
	int	flager;

	i = 0;
	y = 0;
	flager = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y] && map[i][y] != '\n')
		{
			if (map[i][y] == 'E')
				return (texture_cuter(&map[i][y + 3]));
			if (map[i][y] != ' ' && map[i][y] != 'E')
				break ;
			y++;
		}
		i++;
	}
	return (NULL);
}

char	**set_original(char **src, size_t size, int som)
{
	size_t	i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		if (src[som + i][0] == '\n')
			break ;
		map[i] = cus_strdup(src[i + som]);
		i++;
	}
	map[i] = NULL;
	return (map);
}
