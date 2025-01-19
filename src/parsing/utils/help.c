/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 06:40:01 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/19 00:31:23 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	ceil_help(t_parse *map_info, int i, int y, int continues)
{
	if (map_info->map[i][y + 1] != ' ')
		return (-1);
	if (count_word(map_info->map[i], ' ') != 2 || color_syntax(map_info,
			map_info->map[i], 0))
		return (-1);
	continues = i + 1;
	return (continues);
}

int	ns_help(t_parse *map_info, int i, int y, int continues)
{
	if (map_info->map[i][y + 1] != 'O' || map_info->map[i][y + 2] != ' ')
		return (-1);
	if (count_word(map_info->map[i], ' ') != 2)
		return (-1);
	continues = i + 1;
	return (continues);
}

int	w_help(t_parse *map_info, int i, int y, int continues)
{
	if (map_info->map[i][y + 1] != 'E' || map_info->map[i][y + 2] != ' ')
		return (-1);
	if (count_word(map_info->map[i], ' ') != 2)
		return (-1);
	continues = i + 1;
	return (continues);
}

int	e_help(t_parse *map_info, int i, int y, int continues)
{
	if (map_info->map[i][y + 1] != 'A' || map_info->map[i][y + 2] != ' ')
		return (-1);
	if (count_word(map_info->map[i], ' ') != 2)
		return (-1);
	continues = i + 1;
	return (continues);
}

int	floor_help(t_parse *map_info, int i, int y, int continues)
{
	if (map_info->map[i][y + 1] != ' ')
		return (-1);
	if (count_word(map_info->map[i], ' ') != 2 || color_syntax(map_info,
			map_info->map[i], 1))
		return (-1);
	continues = i + 1;
	return (continues);
}
