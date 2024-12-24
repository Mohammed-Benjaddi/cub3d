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

t_parse* map_setter(t_parse* map_info, int ac, char** av) {
    char* line;
    int i = -1;
    map_info->map_size = size_calc(map_info->fd);
    map_info->fd = open(av[1], O_RDONLY);
    map_info->map = (char **)malloc(sizeof(char *) * (map_info->map_size + 1));
    while(++i < map_info->map_size)
        map_info->map[i] = get_next_line(map_info->fd);
    map_info->map[i] = NULL;
    flood_fill(map_info->map, 1, 1);  
    return (map_info);
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
    map_setter(&map_info, ac, av);
    if (map_checker(map_info.map, map_info.map_size))
        return (close(map_info.fd), parse_free(&map_info), perror("Error\nCheck your map content\n"), 1);
    if (syntaxer(&map_info))
        exit(1);
    print_map(map_info.map);
    parse_free(&map_info);
    return (1);
}
