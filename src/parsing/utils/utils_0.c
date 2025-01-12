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
