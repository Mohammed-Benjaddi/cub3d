/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:52:31 by mben-jad          #+#    #+#             */
/*   Updated: 2025/01/19 00:31:23 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

int	final_norm0(char **map, int len, int i, int y)
{
	if ((map[i][y] == 'M' || map[i][y] == 'N' || map[i][y] == 'S'
			|| map[i][y] == 'E' || map[i][y] == 'W') && (i == 0 || y == 0
			|| i == len))
		return (1);
	return (0);
}

int	final_norm1(char **map, int len, int i, int y)
{
	if (((i + 1 <= len) && (map[i][y] == 'M' || map[i][y] == 'N'
		|| map[i][y] == 'S' || map[i][y] == 'E' || map[i][y] == 'W'))
		&& ((int)custom_strlen(map[i + 1]) - 1 < y || map[i + 1][y] == ' '))
		return (1);
	return (0);
}
