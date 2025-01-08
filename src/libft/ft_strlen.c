#include "../../include/libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if(!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int cus_strlen(const char *s)
{
	int	i;

	i = 0;
	if(!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	ft_isdigit(int c) {
	return (c >= 48 && c <= 57);
}