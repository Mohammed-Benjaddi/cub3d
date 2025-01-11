#include "../include/parsing.h"

int map_checker(char** map, int len) {
    int i = 0;
    int y = 0;

    while (map[i]) {
    	y = 0;
    	while (map[i][y] && map[i][y] != '\n') {
    		if ((map[i][y] == 'M') && (i == 0 || y == 0 || i == len))
    			return (1);
    		else if (map[i][y] == 'M' && (map[i][y + 1] == '\n' || map[i][y + 1] == ' ' || map[i][y - 1] == ' '
    			|| custom_strlen(map[i - 1]) - 1 < y || custom_strlen(map[i + 1]) - 1 < y
    			|| map[i + 1][y] == ' ' || map[i - 1][y] == ' '))
    			    return (1);
    		y++;
    	}
	   i++;
    }
    return (0);
}

int position_finder(t_parse* map_info) {
    int i = map_info->som;
    int y = 0;
    int found = 0;

    while (map_info->map[i]) {
        y = 0;
        while (map_info->map[i][y] && map_info->map[i][y] != '\n') {
            if (map_info->map[i][y] != ' ' && map_info->map[i][y] != 'N'
                && map_info->map[i][y] != 'S' && map_info->map[i][y] != 'E'
                && map_info->map[i][y] != 'W' && map_info->map[i][y] != '0'
                && map_info->map[i][y] != '1')
                    return (1);
            if (map_info->map[i][y] == 'W' || map_info->map[i][y] == 'S'
                || map_info->map[i][y] == 'N'|| map_info->map[i][y] == 'E') {
                    map_info->player_x = y;
                    map_info->player_y = i;
                    found++;
                }
            y++;
        }
        i++;
    }
    if (found != 1)
        return (1);
    return (0);
}

t_parse* map_setter(t_parse* map_info, int ac, char** av) {
    char* line;
    int i = -1;
    map_info->som = 0;
    map_info->map_size = size_calc(map_info->fd);
    map_info->fd = open(av[1], O_RDONLY);
    map_info->map = (char **)malloc(sizeof(char *) * (map_info->map_size + 1));
    while(++i < map_info->map_size)
        map_info->map[i] = get_next_line(map_info->fd);
    map_info->map[i] = NULL;
    map_start(map_info);
    if (position_finder(map_info))
        return (NULL);
    return (map_info);
}

void map_start(t_parse* map_info) {
    int i = 0;
    int y = 0;
    while (map_info->map[i]) {
        y = 0;
        while (map_info->map[i][y] && map_info->map[i][y] != '\n') {
            if (map_info->map[i][y] == 'N' || map_info->map[i][y] == 'S' 
                || map_info->map[i][y] == 'E' || map_info->map[i][y] == 'W'
                || map_info->map[i][y] == 'C' || map_info->map[i][y] == 'F')
                    break;
            else if (map_info->map[i][y] == '0' || map_info->map[i][y] == '1')
                map_info->som = i;
            y++;
        }
        if (map_info->som != 0)
            break;
        i++;
    }
    return;
}

void flood_filler(t_parse *map_info) {
    int i = 0;
    int y = 0;

    i = map_info->som;
    while (map_info->map[i]) {
        y = 0;
        while (map_info->map[i][y] && map_info->map[i][y] != '\n') {
            if (map_info->map[i][y] == '0')
                flood_fill(map_info->map, i, y);
            y++;
        }
        i++;
    }
}

int parse_entry(t_parse *map_info, int ac, char** av) {
    if (ac != 2)
        return (write(2, "Error\ninvalid number of arguments\n", 34), 0);
    map_info->fd = open(av[1], O_RDONLY);
    if (map_info->fd == -1)
        return (write(2, "Error\nFailed to open file\n", 26), 0);
    if (name_checker(av[1]))
        return (close(map_info->fd), write(2, "Error\nInvalid map name\n", 23), 0);
    if (!map_setter(map_info, ac, av))
        return (map_free(map_info), write(2, "Error\nCheck your map content\n", 29), 0);
    flood_filler(map_info);
    if (map_checker(&map_info->map[map_info->som], map_info->map_size))
        return (map_free(map_info), close(map_info->fd), write(2, "Error\nCheck your map content\n", 29), 0);
    if (syntaxer(map_info))
        return (close(map_info->fd), write(2, "Error\nCheck your map content\n", 29), 0);
    return (1);
}

// print_texture(&map_info);
// print_map(map_info.map);
// parse_free(&map_info);
//make sure to free and delete unused functions (E.G print_map, print_texture...)
//don't forget to protect images