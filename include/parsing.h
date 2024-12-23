#ifndef PARSING_H
# define PARSING_H

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

typedef struct s_parse {
    int     fd;
    char**  map;
    char*   NO_TEXTURE;
    char*   SO_TEXTURE;
    char*   WE_TEXTURE;
    char*   EA_TEXTURE;
    size_t  map_size;
}   
t_parse;

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t  size_calc(int fd);
size_t  custom_strlen(char* string);
int     syntaxer(t_parse* map_info);
int     structer(char** map, int stop);
void    parse_free(char** map);
void    print_map(char** map);
void    flood_fill(char** map, int i, int y);
int     parse_entry(int ac, char** av);
char*   norther(char** map);
char*   easter(char** map);
char*   wester(char** map);
char*   norther(char** map);
#endif