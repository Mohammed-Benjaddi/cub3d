/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 05:35:09 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/17 22:07:17 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing_bonus.h"

int	r(t_rgb *rgb, char *line, int color)
{
	while (line[rgb->i] == ' ')
		rgb->i++;
	if (color == 0)
	{
		if (line[rgb->i] != 'C')
			return (1);
	}
	else if (color == 1)
	{
		if (line[rgb->i] != 'F')
			return (1);
	}
	rgb->i++;
	while (line[rgb->i] == ' ')
		rgb->i++;
	if (!ft_isdigit(line[rgb->i]))
		return (1);
	while (ft_isdigit(line[rgb->i]))
	{
		rgb->r = rgb->r * 10 + (line[rgb->i] - '0');
		rgb->i++;
	}
	if (rgb->r < 0 || rgb->r > 255)
		return (1);
	return (0);
}

void	rgb_init(t_rgb *rgb)
{
	rgb->i = 0;
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
}

int	g(t_rgb *rgb, char *line)
{
	if (line[rgb->i] != ',')
		return (1);
	rgb->i++;
	if (!ft_isdigit(line[rgb->i]))
		return (1);
	while (ft_isdigit(line[rgb->i]))
	{
		rgb->g = rgb->g * 10 + (line[rgb->i] - '0');
		rgb->i++;
	}
	if (rgb->g < 0 || rgb->g > 255)
		return (1);
	return (0);
}

int	b(t_rgb *rgb, char *line)
{
	if (line[rgb->i] != ',')
		return (1);
	rgb->i++;
	if (!ft_isdigit(line[rgb->i]))
		return (1);
	while (ft_isdigit(line[rgb->i]))
	{
		rgb->b = rgb->b * 10 + (line[rgb->i] - '0');
		rgb->i++;
	}
	if (rgb->b < 0 || rgb->b > 255)
		return (1);
	return (0);
}

void	free_original(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}
