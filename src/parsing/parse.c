#include "../include/get_next_line.h"
#include <stdio.h>

size_t custom_strlen(char* string) {
	size_t i = 0;

    while (string[i] && string[i] != '\n')
		i++;
	return (i);
}

void    parse_free(char** map) {
    int i = 0;

    while (map[i]) {
        free(map[i]);
        i++;
    }
    free(map[i]);
    free(map);
}

int name_checker(char* map_name) {
    int i = 0;
    int len = ft_strlen(map_name);
    
    if (map_name[len - 1] != 'b' || map_name[len - 2] != 'u' 
        || map_name[len - 3] != 'c' || map_name[len - 4] != '.')
        return (write(2, "Error\n", 6), 0);
    return (1);
}

void flood_fill(char** map, int i, int y) {
	if (!map[i] || !map[i][y] || map[i][y] == ' '
		|| map[i][y] == '1' || map[i][y] == '\n' || map[i][y] == 'M') {
		return;	
	}
	map[i][y] = 'M';
	if (!map[i + 1] || custom_strlen(map[i + 1]) - 1 > y)
		flood_fill(map, i + 1, y);			
	if (i != 0 && custom_strlen(map[i - 1]) - 1 > y)
		flood_fill(map, i - 1, y);
	flood_fill(map, i, y + 1);
    if (y != 0)
        flood_fill(map, i, y - 1);
}

char** map_setter(int ac, char** av) {
    int     i;
    char**  map;
    int     map_size;
    int     fd;
    char*   line;
    
    fd = open(av[1], O_RDONLY);
    if (fd == -1 || !name_checker(av[1])) {
        write(2, "Error\nInvalid map name\n", 23);
        return (NULL);
    }

    map_size = 0;
    while (1) {
        line = get_next_line(fd);
        if (!line)
            break;
        free(line);
        map_size++;
    }

    close(fd);
    fd = open(av[1], O_RDONLY);
    i = 0;
    map = (char **)malloc(sizeof(char *) * (map_size + 1));
    while(i < map_size) {
        map[i] = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    flood_fill(map, 1, 1);  
    return (map);
}

int map_checker(char** map, int len) {
    int i = 0;
    int y = 0;
    int shit = 0;
    while (map[i]) {
    	y = 0;
    	while (map[i][y] && map[i][y] != '\n') {
    		if ((map[i][y] == 'M') && (i == 0 || y == 0 || i == len))
    			shit = 1;
    		else if (map[i][y] == 'M' && (map[i][y + 1] == '\n' || map[i][y + 1] == ' ' || map[i][y - 1] == ' '
    			|| custom_strlen(map[i - 1]) - 1 < y || custom_strlen(map[i + 1]) - 1 < y
    			|| map[i + 1][y] == ' ' || map[i - 1][y] == ' '))
    			shit = 1;
    		y++;
    	}
	   i++;
    }
    return (shit);
}

void print_map(char** map) {
    int i = 0;
    int y = 0;
    while (map[i]) {
        printf("%s", map[i]);
        i++;
    }
}

int parse_entry(int ac, char** av) {
    if (ac != 2)
        return (write(2, "Error\ninvalid number of arguments\n", 34), 0);
    char** map = map_setter(ac, av);
    if (!map)
        return 0;
    int len = 0;
    while (map[len])
	    len++;
    len--;
    if (map_checker(map, len))
        return (parse_free(map), write(2, "Error\nCheck your map content\n", 29), 0);
    print_map(map);
    parse_free(map);
    return (1);
}