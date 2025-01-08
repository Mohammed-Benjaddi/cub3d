#include "../../../include/parsing.h"

void map_free(t_parse *map_info) {
    int i = 0;
    while (map_info->map[i]) {
        free(map_info->map[i]);
        i++;
    }
    free(map_info->map[i]);
    free(map_info->map);
}