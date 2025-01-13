/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:15:47 by bbelarra          #+#    #+#             */
/*   Updated: 2025/01/13 08:27:27 by bbelarra42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

size_t	count_word(char *s, char delimiter)
{
	size_t	words;
	int		i;

	words = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != delimiter)
		{
			words++;
			while (s[i] && s[i] != delimiter)
				i++;
		}
		else if (s[i] == delimiter)
			i++;
	}
	return (words);
}

size_t	custom_strlen(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	return (i);
}

void	init_syn(t_syn *syn)
{
	syn->i = 0;
	syn->y = 0;
	syn->f = 0;
	syn->c = 0;
	syn->n = 0;
	syn->s = 0;
	syn->w = 0;
	syn->e = 0;
	syn->continues = 0;
}

void	texture_initilizer(t_parse *map_info)
{
	map_info->no_texture = norther(map_info->map);
	map_info->so_texture = souther(map_info->map);
	map_info->we_texture = wester(map_info->map);
	map_info->ea_texture = easter(map_info->map);
}
