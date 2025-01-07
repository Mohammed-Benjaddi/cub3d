#include "../../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int	i;
	int	len;

	len = ft_strlen(s1);
	i = 0;
	res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*cus_strdup(const char *s1)
{
	char	*res;
	int	i;
	int	len;

	len = cus_strlen(s1);
	i = 0;
	res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
