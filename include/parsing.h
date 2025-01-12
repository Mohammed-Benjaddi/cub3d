#ifndef PARSING_H
# define PARSING_H

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <errno.h>

typedef struct s_parse {
    int     ceiling_color;
    int     floor_color;
    int     fd;
    char**  map;

    char*   NO_TEXTURE;
    char*   SO_TEXTURE;
    char*   WE_TEXTURE;
    char*   EA_TEXTURE;


    size_t  som;
    size_t  map_size;

    int     player_x;
    int     player_y;
}
t_parse;


int north_checker(t_parse* map_info, int continues, int* N);
int south_checker(t_parse* map_info, int continues, int* S);
int west_checker(t_parse* map_info, int continues, int* W);
int east_checker(t_parse* map_info, int continues, int* E);


int     color_syntax(t_parse *map_info, char *line, int color);

int     floor_check(t_parse *map_info, int continues, int *F);
int     ceil_check(t_parse *map_info, int continues, int *C);

void    map_start(t_parse* map_info);
int     position_finder(t_parse* map_info);

char*   norther(char** map);
char*   easter(char** map);
char*   wester(char** map);
char*   souther(char** map);

char	*texture_cuter(char *string);
size_t  count_word(char* string, char delimiter);
size_t  size_calc(int fd);
size_t  custom_strlen(char* string);
int     syntaxer(t_parse* map_info);
int     structer(char** map, int stop);

void    map_free(t_parse *map_info);
void    parse_free(t_parse* map_info);

void    print_map(char** map);
void    flood_fill(char** map, int i, int y);
int     parse_entry(t_parse *map_info, int ac, char** av);
void    flood_filler(t_parse *map_info);
#endif
