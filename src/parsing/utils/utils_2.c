#include "../../../include/parsing.h"
#include "../../../include/libft.h"

int where(char* string) {
    int i = 0;
    while (string[i] && string[i] != '\n' && string[i] != ' ')
        i++;
    return (i);
}

char* texture_cuter(char* string) {
    int i = 0;
    int index = where(string);
    char* no_texture = ft_substr(string, 0, index);
    return (no_texture);
}

char* norther(char** map) {
    int i = 0;
    int y = 0;
    int flager = 0;

    while (map[i]) {
        y = 0;
        while(map[i][y] && map[i][y] != '\n') {
            if (map[i][y] != ' ') {
                if (map[i][y] != 'N' && map[i][y + 1] != 'O')
                    return NULL;
                flager = 1;
                break;
    
            }
            y++;
        }
        if (flager == 1)
            break;
    }
    return (texture_cuter(&map[i][y]));
}

int souther();
int wester();
int easter();

int syntaxer(t_parse* map_info) {
    map_info->NO_TEXTURE = norther(map_info->map);
    map_info->SO_TEXTURE = souther(map_info->map);
    map_info->WE_TEXTURE = wester(map_info->map);
    map_info->EA_TEXTURE = easter(map_info->map);
}