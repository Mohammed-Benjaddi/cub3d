#include "../../../include/parsing.h"

size_t size_calc(int fd) {
    char* line;
    size_t map_size = 0;
    while (1) {
        line = get_next_line(fd);
        if (!line)
            break;
        free(line);
        map_size++;
    }
    close(fd);
    return (map_size);
}

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

void print_map(char** map) {
    int i = 0;
    int y = 0;
    while (map[i]) {
        printf("%s", map[i]);
        i++;
    }
}

int name_checker(char* map_name) {
    int i = 0;
    int len = ft_strlen(map_name);
    
    if (map_name[len - 1] != 'b' || map_name[len - 2] != 'u' 
        || map_name[len - 3] != 'c' || map_name[len - 4] != '.')
        return (write(2, "Error\n", 6), 1);
    return (0);
}

