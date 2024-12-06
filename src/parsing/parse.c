#include "../include/get_next_line.h"
#include <stdio.h>

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
        break;
        map_size++;
    }

    close(fd);
    i = 0;
    map = (char **)malloc(sizeof(char *) * (map_size + 1));
    while(i < map_size) {
        map[i] = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    return (map);
}
int parse_entry(int ac, char** av) {

    if (ac != 2)
        return (0);

    char** map = map_setter(ac, av);
    if (!map)
        return 0;
    
    return (1);
}
