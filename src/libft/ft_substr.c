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

#include "../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*malloca;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (len > slen - start)
		len = slen - start;
	if (start > slen)
		len = 0;
	malloca = (char *)malloc(sizeof(char) * (len + 1));
	if (malloca == NULL)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		malloca[i] = s[i + start];
		i++;
	}
	malloca[i] = '\0';
	return (malloca);
}
