/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:15:47 by bbelarra          #+#    #+#             */
/*   Updated: 2025/01/17 22:02:39 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft_bonus.h"

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
