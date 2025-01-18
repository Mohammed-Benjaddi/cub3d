/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-jad <mben-jad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:19 by bbelarra          #+#    #+#             */
/*   Updated: 2025/01/17 22:17:44 by mben-jad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include "libft_bonus.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_struct
{
	int		i;
	int		y;
	int		readed;
	char	*final_string;
	char	*buffer;
}			t_norm_fix;

int			name_checker(char *map_name);
char		*filler(char *holder, int readed);
char		*cuter(char *holder, int readed);
void		little_conca(char *dst, char *src);
void		little_copy(char *dst, char *src);
char		*ft_strjoin(char *s1, char *s2);
int			newline_finder(char *string);
char		*get_next_line(int fd);
void		*ft_cleaner(char **holder, char *buffer, int flag);
#endif