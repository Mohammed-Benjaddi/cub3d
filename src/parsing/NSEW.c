#include "../../include/parsing.h"

int south_checker(t_parse* map_info, int continues) {
    int i = continues;
    int y = 0;
    while (map_info->map[i]) {
        y = 0;
        while (map_info->map[i][y] && map_info->map[i][y] != '\n') {
            if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'S')
                return (-1);
            if (map_info->map[i][y] == 'S') {
                if (map_info->map[i][y + 1] != 'O' || map_info->map[i][y + 2] != ' ')
                    return (-1);
                if (count_word(map_info->map[i], ' ') != 2)
                    return (-1);
                continues = i;
                return (continues);
            }
            y++;
        }
        i++;
    }
    return (-1);
}

int north_checker(t_parse* map_info, int continues) {
    int i = continues;
    int y = 0;
    while (map_info->map[i]) {
        y = 0;
        while (map_info->map[i][y] && map_info->map[i][y] != '\n') {
            if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'N')
                return (-1);
            if (map_info->map[i][y] == 'N') {
                if (map_info->map[i][y + 1] != 'O' || map_info->map[i][y + 2] != ' ')
                    return (-1);
                if (count_word(map_info->map[i], ' ') != 2)
                    return (-1);
                continues = i;
                return (continues);
            }
            y++;
        }
        i++;
    }
    return (-1);
}

int east_checker(t_parse* map_info, int continues) {
    int i = continues;
    int y = 0;
    while (map_info->map[i]) {
        y = 0;
        while (map_info->map[i][y] && map_info->map[i][y] != '\n') {
            if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'E')
                return (-1);
            if (map_info->map[i][y] == 'E') {
                if (map_info->map[i][y + 1] != 'A' || map_info->map[i][y + 2] != ' ')
                    return (-1);
                if (count_word(map_info->map[i], ' ') != 2)
                    return (-1);
                continues = i;
                return (continues);
            }
            y++;
        }
        i++;
    }
    return (-1);
}

int west_checker(t_parse* map_info, int continues) {
    int i = continues;
    int y = 0;
    while (map_info->map[i]) {
        y = 0;
        while (map_info->map[i][y] && map_info->map[i][y] != '\n') {
            if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'W')
                return (-1);
            if (map_info->map[i][y] == 'W') {
                if (map_info->map[i][y + 1] != 'E' || map_info->map[i][y + 2] != ' ')
                    return (-1);
                if (count_word(map_info->map[i], ' ') != 2)
                    return (-1);
                continues = i;
                return (continues);
            }
            y++;
        }
        i++;
    }
    return (-1);
}