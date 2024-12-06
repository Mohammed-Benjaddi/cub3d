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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_norm_fix	var;
	static char	*holder;
	char		*final_string;

	var.buffer = malloc(BUFFER_SIZE + 1);
	// if (read(fd, var.buffer, 0) == -1 || fd < 0 || 
	// 	BUFFER_SIZE <= 0 || fd > OPEN_MAX || BUFFER_SIZE > INT_MAX)
	// 	return (ft_cleaner(&holder, var.buffer, 1));
	while (1)
	{
		var.readed = read(fd, var.buffer, BUFFER_SIZE);
		if (var.readed == 0 || var.readed == -1)
			break ;
		var.buffer[var.readed] = '\0';
		holder = ft_strjoin(holder, var.buffer);
		if (newline_finder(holder) != -1)
			break ;
	}
	free(var.buffer);
	if (ft_strlen(holder) == 0)
		return (ft_cleaner(&holder, NULL, 0));
	var.readed = newline_finder(holder);
	final_string = filler(holder, var.readed);
	holder = cuter(holder, var.readed);
	return (final_string);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		total_len;
	char	*malloca;

	if (!s1)
		s1 = ft_strdup("");
	total_len = ft_strlen(s1) + ft_strlen(s2);
	malloca = (char *)malloc(sizeof(char) * (total_len + 1));
	if (malloca == NULL)
	{
		free(s1);
		return (NULL);
	}
	little_copy(malloca, s1);
	little_conca(malloca, s2);
	free(s1);
	malloca[total_len] = '\0';
	return (malloca);
}

void	little_copy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ;
}

void	little_conca(char *dst, char *src)
{
	int	dlen;
	int	i;

	i = 0;
	dlen = ft_strlen(dst);
	while (src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
}

int	newline_finder(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (-2);
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
