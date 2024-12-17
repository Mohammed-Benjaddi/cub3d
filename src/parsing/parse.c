#include "../include/get_next_line.h"
#include <stdio.h>

void flood_fill(char** map, int i, int y);

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
    int i;
    i = 0;
    int len = ft_strlen(map_name);
    if (map_name[len - 1] != 'b' || map_name[len - 2] != 'u' 
        || map_name[len - 3] != 'c' || map_name[len - 4] != '.')
        return (0);
    return (1);
}

char** map_setter(int ac, char** av) {

    int     i;
    char**  map;
    int     map_size;
    int     fd;
    char*   line;
    
    fd = open(av[1], O_RDONLY);
    if (fd == -1 || !name_checker(av[1])) {
        write(2, "error: invalid map name\n", 24);
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

void flood_fill(char** map, int i, int y) {
	if (!map[i] || !map[i][y] || i == 0 || y == 0 || map[i][y] == ' ' 
		|| map[i][y] == '1' || map[i][y] == '\n' || map[i][y] == 'M') {
		return;	
	}
	//if (map[i][y] == '1' || map[i][y] == '\0' || map[i][y] == '\n' )
	//	return ;
	map[i][y] = 'M';
	printf(">> %d and %d \n", custom_strlen(map[i + 1]) - 1, y);
	if (custom_strlen(map[i + 1]) - 1 > y)
	{
		printf("badreddine belarradi\n");
		flood_fill(map, i + 1, y);			
	}
	if (custom_strlen(map[i - 1]) - 1 > y)
		flood_fill(map, i - 1, y);
	flood_fill(map, i, y + 1);
	flood_fill(map, i, y - 1);

}

int parse_entry(int ac, char** av) {

    if (ac != 2)
        return (0);

    char** map = map_setter(ac, av);
    if (!map)
        return 0;
    int i = 0;
    while (map[i]) {
	    printf("%s", map[i]);
	    i++;
    }
    i = 0;
    while (map[i]) {
	    free(map[i]);
	    i++;
    }
    free(map[i]);
    free(map);
    return (1);
}
