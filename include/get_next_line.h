/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbelarra42 <bbelarra@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:50:19 by bbelarra          #+#    #+#             */
/*   Updated: 2024/05/18 15:25:52 by bbelarra42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
typedef struct t_struct
{
	int		i;
	int		y;
	int		readed;
	char	*final_string;
	char	*buffer;
}			t_norm_fix;

char		*filler(char *holder, int readed);
char		*cuter(char *holder, int readed);
void		little_conca(char *dst, char *src);
void		little_copy(char *dst, char *src);
char		*ft_strjoin(char *s1, char *s2);
int			newline_finder(char *string);
char		*get_next_line(int fd);
void		*ft_cleaner(char **holder, char *buffer, int flag);
#endif