#include <cub3D.h>

double normalize_angle(float angle) {
  angle = fmod(angle, 2 * M_PI);
  if(angle < 0)
    angle = (2 * M_PI) + angle;
  return angle;
}

double calculate_distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void get_the_smaller_distance(t_game *game, t_ray *ray, double horzHitDistance, double vertHitDistance)
{
  t_hor_intersection *hor_inter;
  t_ver_intersection *ver_inter;

  hor_inter = &game->h_intersection;
  ver_inter = &game->v_intersection;
  if (vertHitDistance < horzHitDistance) 
  {
    ray->distance = vertHitDistance;
    ray->wallHitX = ver_inter->vertWallHitX;
    ray->wallHitY = ver_inter->vertWallHitY;
    ray->wallHitContent = ver_inter->vertWallContent;
    ray->wasHitVertical = true;
  } 
  else 
  {
    ray->distance = horzHitDistance;
    ray->wallHitX = hor_inter->horzWallHitX;
    ray->wallHitY = hor_inter->horzWallHitY;
    ray->wallHitContent = hor_inter->horzWallContent;
    ray->wasHitVertical = false;
  }
  ray->isRayFacingDown = isRayFacingDown(ray->ray_angle);
  ray->isRayFacingUp = isRayFacingUp(ray->ray_angle);
  ray->isRayFacingLeft = isRayFacingLeft(ray->ray_angle);
  ray->isRayFacingRight = isRayFacingRight(ray->ray_angle);
}

void castRay(t_game *game, t_ray *ray, float ray_angle) {
  t_hor_intersection *hor_inter;
  t_ver_intersection *ver_inter;
  double horzHitDistance;
  double vertHitDistance;

  ray_angle = normalize_angle(ray_angle);
  hor_inter = &game->h_intersection;
  ver_inter = &game->v_intersection;
  horizontal_intersection(game, hor_inter, ray_angle);
  vertical_intersection(game, ver_inter, ray_angle);
  if(hor_inter->foundHorzWallHit)
    horzHitDistance = calculate_distance(game->player.player_x, game->player.player_y,
      hor_inter->horzWallHitX, hor_inter->horzWallHitY);
  else
    horzHitDistance = INT_MAX;
  if(ver_inter->foundVertWallHit)
    vertHitDistance = calculate_distance(game->player.player_x, game->player.player_y, 
      ver_inter->vertWallHitX, ver_inter->vertWallHitY);
  else
    vertHitDistance = INT_MAX;
  ray->ray_angle = ray_angle;
  get_the_smaller_distance(game, ray, horzHitDistance, vertHitDistance);
}

void render_rays(t_game *game)
{
  int i;

  i = 0;
  i = 0;
  while(i < NUM_RAYS)
  {
    // draw_line(game, game->player, game->rays[i]);
    i++;
  }
}

void cast_rays(t_game *game)
{
  double ray_angle = game->player.rotation_angle - (FOV / 2); 
  int i = 0;
  while (i < game->width)
  {
    castRay(game, &game->rays[i], ray_angle);
    ray_angle += (FOV / NUM_RAYS);
    i++;
  }
  // render_rays(game);
}
