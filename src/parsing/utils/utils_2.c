#include "../../../include/parsing.h"

int where(char* string) {
    int i = 0;
    while (string[i] && string[i] != '\n' && string[i] != ' ')
        i++;
    return (i);
}

char* texture_cuter(char* string) {
    int i = 0;
    int start = 0;
    while (string[start] == ' ')
        start++;
    int index = where(&string[start]);
    char* no_texture = ft_substr(string, start, index);
    return (no_texture);
}

char* norther(char** map) {
    int i = 0;
    int y = 0;

    while (map[i]) {
        y = 0;
        while(map[i][y] && map[i][y] != '\n') {
                if (map[i][y] == 'N')
                    return (texture_cuter(&map[i][y + 3]));
                if (map[i][y] != ' ' && map[i][y] != 'N')
                    break;
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
                if (map[i][y] == 'S')
                    return (texture_cuter(&map[i][y + 3]));
                if (map[i][y] != ' ' && map[i][y] != 'S')
                    break;
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
            if (map[i][y] == 'W')
                return (texture_cuter(&map[i][y + 3]));
            if (map[i][y] != ' ' && map[i][y] != 'W')
                break;
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
            if (map[i][y] == 'E')
                return (texture_cuter(&map[i][y + 3]));
            if (map[i][y] != ' ' && map[i][y] != 'E')
                break;
            y++;
        }
        i++;
    }
    return NULL;
}

int syntaxer(t_parse* map_info) {
    int i = 0;
    int y = 0;

    int F = 0;
    int C = 0;

    int N = 0;
    int S = 0;
    int W = 0;
    int E = 0;
    int continues = 0;
    while (i < map_info->som) {
        y = 0;
        while (map_info->map[i][y] && map_info->map[i][y] != '\n') {
            if (map_info->map[i][y] == 'N') {
                continues = north_checker(map_info, i, &N);
                break;
            }
            else if (map_info->map[i][y] == 'S') {
                continues = south_checker(map_info, i, &S);
                break;
            }
            else if (map_info->map[i][y] == 'W') {
                continues = west_checker(map_info, i, &W);
                break;
            }
            else if (map_info->map[i][y] == 'E') {
                continues = east_checker(map_info, i, &E);
                break;
            }
            else if (map_info->map[i][y] == 'C') {
                continues = ceil_check(map_info, i, &C);
                break;
            }
            else if (map_info->map[i][y] == 'F') {
                continues = floor_check(map_info, i, &F);
                break;
            }
            else if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'N' 
                && map_info->map[i][y] != 'S' && map_info->map[i][y] != 'W'
                && map_info->map[i][y] != 'E' && map_info->map[i][y] != 'C'
                && map_info->map[i][y] != 'F' && map_info->map[i][y] != '\n')
                    return (1);
            y++;
        }
        if (continues == -1)
            return (1);
        i++;
    }
    if (S != 1 || N != 1 || E != 1 || W != 1 || C != 1 || F != 1)
        return (1);
    map_info->NO_TEXTURE = norther(map_info->map);
    map_info->SO_TEXTURE = souther(map_info->map);
    map_info->WE_TEXTURE = wester(map_info->map);
    map_info->EA_TEXTURE = easter(map_info->map);
    return (0);
}
