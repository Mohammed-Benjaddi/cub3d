#include "../../include/parsing.h"

int south_checker(t_parse* map_info, int continues, int* S) {
    int i = continues;
    int y = 0;
    if ((*S != 0))
        return (-1);
    (*S) = 1;
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
                continues = i + 1;
                return (continues);
            }
            y++;
        }
        i++;
    }
    return (-1);
}

int north_checker(t_parse* map_info, int continues, int* N) {
    int i = continues;
    int y = 0;
    if ((*N != 0))
        return (-1);
    (*N) = 1;
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
                continues = i + 1;
                return (continues);
            }
            y++;
        }
        i++;
    }
    return (-1);
}

int east_checker(t_parse* map_info, int continues, int* E) {
    int i = continues;
    int y = 0;
    if ((*E != 0))
        return (-1);
    (*E) = 1;
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
                continues = i + 1;
                return (continues);
            }
            y++;
        }
        i++;
    }
    return (-1);
}

int west_checker(t_parse* map_info, int continues, int* W) {
    int i = continues;
    int y = 0;
    if ((*W != 0))
        return (-1);
    (*W) = 1;
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
                continues = i + 1;
                return (continues);
            }
            y++;
        }
        i++;
    }
    return (-1);
}