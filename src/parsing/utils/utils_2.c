#include "../../../include/parsing.h"

int where(char* string) {
    int i = 0;
    i++;
    while (string[i] && string[i] != '\n' && string[i] != ' ')
        i++;
    return (i);
}

char* texture_cuter(char* string) {
    int i = 0;
    int start = 0;
    while (string[start] && string[start] != ' ')
        start++;
    int index = where(string);
    char* no_texture = ft_substr(string, start, index);
    return (no_texture);
}

char* norther(char** map) {
    int i = 0;
    int y = 0;

    while (map[i]) {
        y = 0;
        while(map[i][y] && map[i][y] != '\n') {
            if ((map[i][y] == ' '  || y == 0) && map[i][y + 1] == 'N'
                && map[i][y + 2] == 'O' && (map[i][y + 3] == ' ' 
                    || map[i][y + 3] == '\n' || !map[i][y + 3]))
                return (texture_cuter(&map[i][y + 3]));
            y++;
        }
        i++;
    }
    return NULL;
}

char* souther(char** map) {
    int i = 0;
    int y = 0;
    int flager = 0;

    while (map[i]) {
        y = 0;
        while(map[i][y] && map[i][y] != '\n') {
            if ((map[i][y] == ' ' || y == 0) && map[i][y + 1] == 'S'
                && map[i][y + 2] == 'O' && (map[i][y + 3] == ' ' 
                    || map[i][y + 3] == '\n' || !map[i][y + 3]))
                return (texture_cuter(&map[i][y]));
            y++;
        }
        i++;
    }
    return NULL;
}
char* wester(char** map){
    int i = 0;
    int y = 0;
    int flager = 0;

    while (map[i]) {
        y = 0;
        while(map[i][y] && map[i][y] != '\n') {
            if ((map[i][y] == ' ' || y == 0) && map[i][y + 1] == 'W'
                && map[i][y + 2] == 'E' && (map[i][y + 3] == ' ' 
                    || map[i][y + 3] == '\n' || !map[i][y + 3]))
                return (texture_cuter(&map[i][y]));
            y++;
        }
        i++;
    }
    return NULL;
}

char* easter(char** map) {
    int i = 0;
    int y = 0;
    int flager = 0;

    while (map[i]) {
        y = 0;
        while(map[i][y] && map[i][y] != '\n') {
            if ((map[i][y] == ' ' || y == 0) && map[i][y + 1] == 'E'
                && map[i][y + 2] == 'A' && (map[i][y + 3] == ' ' 
                    || map[i][y + 3] == '\n' || !map[i][y + 3]))
                return (texture_cuter(&map[i][y]));
            y++;
        }
        i++;
    }
    return NULL;
}

int syntaxer(t_parse* map_info) {
    map_info->NO_TEXTURE = norther(map_info->map);
    printf("%s\n", map_info->NO_TEXTURE);
    map_info->SO_TEXTURE = souther(map_info->map);
    map_info->WE_TEXTURE = wester(map_info->map);
    map_info->EA_TEXTURE = easter(map_info->map);
    exit(1);
}