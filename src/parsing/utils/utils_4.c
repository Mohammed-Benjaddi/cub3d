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
