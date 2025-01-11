#include <MLX42/MLX42.h>

typedef struct s_render {
    int i;
    double distance_proj_plane;
    double proj_wall_height;
    double perp_distance;
    int wall_strip_height;
    int wall_bottom_pixel;
    int wall_top_pixel;
    int y;
    int tex_x;
    int tex_y;
    uint32_t color;
    mlx_texture_t *texture;
    float tile_size = TILE_SIZE;
} t_render