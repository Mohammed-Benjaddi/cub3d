#ifndef PARSING_H
# define PARSING_H

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_parse {
    int     fd;
    char**  map;
    size_t  map_size;
}   
t_parse;

size_t  size_calc(int fd);
size_t  custom_strlen(char* string);
void    parse_free(char** map);
void    print_map(char** map);
void    flood_fill(char** map, int i, int y);
int     parse_entry(int ac, char** av);

#endif