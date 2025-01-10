#include <cub3D.h>

void floor_ceiling(t_game *game)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while(i < game->height)
  {
    j = 0;
    while(j < game->width)
    {
      if(i < game->height / 2)
        ft_put_pixel(game->img, j, i, game->map_info->ceiling_color);
      else
        ft_put_pixel(game->img, j, i, game->map_info->floor_color);
      j++;
    }
    i++;
  }
}

int get_top_pixel(t_game *game, int wall_strip_hight)
{
  int wall_top_pixel;

  wall_top_pixel = (game->height / 2) - (wall_strip_hight / 2);
  if(wall_top_pixel < 0)
    wall_top_pixel = 0;
  return wall_top_pixel;
}

int get_bottom_pixel(t_game *game, int wall_strip_hight)
{
  int wall_bottom_pixel;
  wall_bottom_pixel = (game->height / 2) + (wall_strip_hight / 2);
  if(wall_bottom_pixel > game->height)
    wall_bottom_pixel = game->height;
  return wall_bottom_pixel;
}

int get_texture_x(t_ray *ray, mlx_texture_t *texture, float tile_size)
{
    int tex_x;

    if (ray->wasHitVertical)
        tex_x = (int)(ray->wallHitY / tile_size * texture->width) % texture->width;
    else
        tex_x = (int)(ray->wallHitX / tile_size * texture->width) % texture->width;

    return tex_x;
}

void render_walls(t_game *game, t_ray *rays)
{
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

    i = 0;
    floor_ceiling(game);

    while (i < NUM_RAYS)
    {
        perp_distance = rays[i].distance * cos(rays[i].ray_angle - game->player.rotation_angle);
        distance_proj_plane = (game->width / 2) * tan(FOV / 2);
        proj_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
        wall_strip_height = (int)proj_wall_height;
        wall_bottom_pixel = get_bottom_pixel(game, wall_strip_height);
        wall_top_pixel = get_top_pixel(game, wall_strip_height);

        if (rays[i].ray_angle >= 0 && rays[i].ray_angle < M_PI / 2)
            texture = game->ea_texture;
        else if (rays[i].ray_angle >= M_PI / 2 && rays[i].ray_angle < M_PI)
            texture = game->so_texture;
        else if (rays[i].ray_angle >= M_PI && rays[i].ray_angle < 3 * M_PI / 2)
            texture = game->we_texture;
        else if (rays[i].ray_angle >= 3 * M_PI / 2 && rays[i].ray_angle < 2 * M_PI)
            texture = game->no_texture;

        tex_x = get_texture_x(&rays[i], texture, tile_size);

        y = wall_top_pixel;
        while (y < wall_bottom_pixel)
        {
            tex_y = (int)(((y - wall_top_pixel) / (double)wall_strip_height) * texture->height);

            tex_x = tex_x % texture->width;
            tex_y = tex_y % texture->height;
            color = ((uint32_t*)texture->pixels)[tex_y * texture->width + tex_x];

            uint8_t r = (color >> 24) & 0xFF;
            uint8_t g = (color >> 16) & 0xFF;
            uint8_t b = (color >> 8) & 0xFF;
            uint8_t a = color & 0xFF;

            color = ((uint32_t)(b << 24) | (uint32_t)(g << 16) | (uint32_t)(r << 8) | (uint32_t)(a));

            ft_put_pixel(game->img, i, y, color);
            y++;
        }
        i++;
    }
}


// void render_walls(t_game *game, t_ray *rays)
// {
//     int i;
//     double distance_proj_plane;
//     double proj_wall_height;
//     double perp_distance;
//     int wall_strip_height;
//     int wall_bottom_pixel;
//     int wall_top_pixel;
//     int y;
//     int tex_x;  // Texture X coordinate
//     int tex_y;  // Texture Y coordinate
//     uint32_t color;   // Color of the texture pixel
//     mlx_texture_t *texture;  // Selected texture based on ray direction
//     uint32_t *texture_data; // Pointer to the texture data

//     i = 0;
//     floor_ceiling(game);

//     while (i < NUM_RAYS)
//     {
//         perp_distance = rays[i].distance * cos(rays[i].ray_angle - game->player.rotation_angle);
//         distance_proj_plane = (game->width / 2) * tan(FOV / 2);
//         proj_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
//         wall_strip_height = (int)proj_wall_height;
//         wall_bottom_pixel = get_bottom_pixel(game, wall_strip_height);
//         wall_top_pixel = get_top_pixel(game, wall_strip_height);

//         // Select the correct texture based on ray direction
//         if (rays[i].ray_angle >= 0 && rays[i].ray_angle < M_PI / 2)      // North-East
//             texture = game->ea_texture;
//         else if (rays[i].ray_angle >= M_PI / 2 && rays[i].ray_angle < M_PI)  // South-East
//             texture = game->so_texture;
//         else if (rays[i].ray_angle >= M_PI && rays[i].ray_angle < 3 * M_PI / 2)  // South-West
//             texture = game->we_texture;
//         else if (rays[i].ray_angle >= 3 * M_PI / 2 && rays[i].ray_angle < 2 * M_PI)  // North-West
//             texture = game->no_texture;

//         // Get texture data once, before starting the loop over vertical slices
//         texture_data = (uint32_t *)mlx_get_data_addr(texture);

//         tex_x = get_texture_x(wall_top_pixel, wall_bottom_pixel, &rays[i]);

//         y = wall_top_pixel;
//         while (y < wall_bottom_pixel)
//         {
//             // Calculate texture Y coordinate (vertical)
//             tex_y = (int)(((y - wall_top_pixel) / (double)wall_strip_height) * texture->height);

//             // Fetch the pixel color from the texture
//             color = texture_data[tex_y * texture->width + tex_x];

//             // Set the pixel on the screen using MLX put_pixel
//             mlx_put_pixel(game->img, i, y, color);
//             y++;
//         }
//         i++;
//     }
// }


// void render_walls(t_game *game, t_ray *rays)
// {
//   int i;
//   double distance_proj_plane;
//   double proj_wall_height;
//   double perp_distance;
//   int wall_strip_hight;
//   // int wall_top_pixel;
//   int wall_bottom_pixel;
//   int y;

//   i = 0;
//   floor_ceiling(game);
//   while(i < NUM_RAYS)
//   {
//     perp_distance = rays[i].distance * cos(rays[i].ray_angle - game->player.rotation_angle);
//     distance_proj_plane = (game->width / 2) * tan(FOV / 2);
//     proj_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
//     wall_strip_hight = (int)proj_wall_height;
//     wall_bottom_pixel = get_bottom_pixel(game, wall_strip_hight);
//     y = get_top_pixel(game, wall_strip_hight);
//     while(y < wall_bottom_pixel)
//       ft_put_pixel(game->img, i, y++, WHITE);
//     i++;
//   }
// }
