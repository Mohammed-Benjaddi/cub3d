#include "../../../include/parsing.h"

size_t	count_word(char* s, char delimiter)
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
