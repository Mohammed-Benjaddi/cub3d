/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simo <simo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 04:21:59 by bbelarra          #+#    #+#             */
/*   Updated: 2025/01/19 00:31:23 by simo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*filler(char *holder, int readed)
{
	t_norm_fix	var;

	var.i = 0;
	var.y = 0;
	if (readed == -1)
	{
		var.i = ft_strlen(holder);
		var.final_string = malloc(var.i + 1);
		while (holder[var.y])
		{
			var.final_string[var.y] = holder[var.y];
			var.y++;
		}
		var.final_string[var.y] = '\0';
		return (var.final_string);
	}
	var.final_string = malloc(readed + 2);
	while (var.i <= readed)
	{
		var.final_string[var.i] = holder[var.i];
		var.i++;
	}
	var.final_string[var.i] = '\0';
	return (var.final_string);
}

char	*cuter(char *holder, int readed)
{
	char	*tmp;

	if (readed != -1)
	{
		tmp = ft_strdup(holder + readed + 1);
		free(holder);
		return (tmp);
	}
	readed = ft_strlen(holder);
	tmp = ft_strdup(holder + readed);
	free(holder);
	return (tmp);
}

void	*ft_cleaner(char **holder, char *buffer, int flag)
{
	if (flag == 1)
		free(buffer);
	free(*holder);
	*holder = NULL;
	return (NULL);
}
