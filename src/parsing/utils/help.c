/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 06:40:01 by bbelarra42        #+#    #+#             */
/*   Updated: 2025/01/13 05:15:16 by bbelarra42       ###   ########.fr       */
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
