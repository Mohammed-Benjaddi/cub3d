#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

int     ft_atoi(const char *nptr);
int     ft_strlen(const char *s);
char*   ft_strdup(const char *s1);
char*   ft_substr(char const *s, unsigned int start, size_t len);

int     ft_isdigit(int c);
int     cus_strlen(const char *s);
char*   cus_strdup(const char *s1);
#endif