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

int final_map_check(t_parse* map_info) {
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
    if (final_map_check(map_info))
        return (NULL);
    flood_fill(map_info->map, map_info->player_y, map_info->player_x);  
    return (map_info);
}

void map_start(t_parse* map_info) {
    int i = 0;
    int y = 0;
    while (map_info->map[i]) {
        y = 0;
        while (map_info->map[i][y] && map_info->map[i][y] != '\n') {
            if (map_info->map[i][y] == 'N' || map_info->map[i][y] == 'S' 
                || map_info->map[i][y] == 'E' || map_info->map[i][y] == 'W')
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

int parse_entry(int ac, char** av) {
    t_parse map_info;
    if (ac != 2)
        return (perror("Error\ninvalid number of arguments\n"), 1);
    map_info.fd = open(av[1], O_RDONLY);
    if (map_info.fd == -1)
        return (perror("Error\nFailed to open file\n"), 1);
    if (name_checker(av[1]))
        return (close(map_info.fd), perror("Error\nInvalid map name\n"), 1);
    if (!map_setter(&map_info, ac, av))
        return (perror("Error\n"), 1);
    if (map_checker(map_info.map, map_info.map_size))
        return (close(map_info.fd), parse_free(&map_info), perror("Error\nCheck your map content\n"), 1);
    if (syntaxer(&map_info))
        return (close(map_info.fd), parse_free(&map_info), perror("Error\nInvalid Map\n"), 1);
    print_map(map_info.map);
    parse_free(&map_info);
    return (0);
}
