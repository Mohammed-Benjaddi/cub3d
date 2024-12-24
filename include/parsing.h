#ifndef PARSING_H
# define PARSING_H

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <errno.h>

typedef struct s_parse {
    int     fd;
    char**  map;
    char*   NO_TEXTURE;
    char*   SO_TEXTURE;
    char*   WE_TEXTURE;
    char*   EA_TEXTURE;
    int     F_colors[3];
    int     C_colors[3];
    size_t  map_size;
}   
t_parse;


int north_checker(t_parse* map_info, int continues);
int south_checker(t_parse* map_info, int continues);
int west_checker(t_parse* map_info, int continues);
int east_checker(t_parse* map_info, int continues);

char*   norther(char** map);
char*   easter(char** map);
char*   wester(char** map);
char*   norther(char** map);

size_t  count_word(char* string, char delimiter);
size_t  size_calc(int fd);
size_t  custom_strlen(char* string);
int     syntaxer(t_parse* map_info);
int     structer(char** map, int stop);
void    parse_free(t_parse* map_info);
void    print_map(char** map);
void    flood_fill(char** map, int i, int y);
int     parse_entry(int ac, char** av);
#endif