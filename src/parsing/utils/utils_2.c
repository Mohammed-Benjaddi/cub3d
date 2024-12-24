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
                    return (texture_cuter(&map[i][y]));
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
                return (texture_cuter(&map[i][y]));
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
                return (texture_cuter(&map[i][y]));
            if (map[i][y] != ' ' && map[i][y] != 'E')
                break;
            y++;
        }
        i++;
    }
    return NULL;
}

int syntaxer(t_parse* map_info) {
    int continues =  north_checker(map_info, 0);
    if (continues == -1)
         return (1);
    printf("success\n");
    exit(1);
    // continues = south_checker(map_info, continues);
    // if (continues == -1)
    //     return (1);
    // continues = west_checker(map_info, continues);
    // if (continues == -1)
    //     return (1);
    // continues = east_checker(map_info, continues);
    // if (continues == -1)
    //     return (1);

    // map_info->NO_TEXTURE = norther(map_info->map);
    // map_info->SO_TEXTURE = souther(map_info->map);
    // map_info->WE_TEXTURE = wester(map_info->map);
    // map_info->EA_TEXTURE = easter(map_info->map);
    return (0);
}
