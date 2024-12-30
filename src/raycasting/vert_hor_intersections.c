#include <raycasting.h>

bool map_has_wall(t_game *game, double x, double y) {
    if (x < 0 || x > 720 || y < 0 || y > 420) {
        return true;
    }
    int map_x = floor(x / TILE_SIZE);
    int map_y = floor(y / TILE_SIZE);
    return game->map[map_y][map_x] == '1';
}

void init_horizontal_intersection(t_game *game, t_hor_intersection *hor_inter, double ray_angle)
{
  hor_inter->foundHorzWallHit = false;
  hor_inter->horzWallContent = 0;
  hor_inter->horzWallHitX = 0;
  hor_inter->horzWallHitY = 0;
  hor_inter->yintercept = floor(game->player.player_y / TILE_SIZE) * TILE_SIZE;
  hor_inter->yintercept += isRayFacingDown(ray_angle) ? TILE_SIZE : 0;
  hor_inter->xintercept = game->player.player_x + (hor_inter->yintercept - game->player.player_y) / tan(ray_angle);
  hor_inter->ystep = TILE_SIZE;
  hor_inter->ystep *= isRayFacingUp(ray_angle) ? -1 : 1;
  hor_inter->xstep = TILE_SIZE / tan(ray_angle);
  hor_inter->xstep *= (isRayFacingLeft(ray_angle) && hor_inter->xstep > 0) ? -1 : 1;
  hor_inter->xstep *= (isRayFacingRight(ray_angle) && hor_inter->xstep < 0) ? -1 : 1;
  hor_inter->xToCheck = 0;
  hor_inter->yToCheck = 0;
  hor_inter->nextHorzTouchX = hor_inter->xintercept;
  hor_inter->nextHorzTouchY = hor_inter->yintercept;
}

void init_vertical_intersection(t_game *game, t_ver_intersection *ver_inter, double ray_angle)
{
  ver_inter->foundVertWallHit = false;
  ver_inter->vertWallContent = 0;
  ver_inter->vertWallHitX = 0;
  ver_inter->vertWallHitY = 0;

  ver_inter->xintercept = floor(game->player.player_x / TILE_SIZE) * TILE_SIZE;
  ver_inter->xintercept += isRayFacingRight(ray_angle) ? TILE_SIZE : 0;


  ver_inter->yintercept =  game->player.player_y + (ver_inter->xintercept - game->player.player_x) * tan(ray_angle);
  
  ver_inter->xstep = TILE_SIZE;
  ver_inter->xstep *= isRayFacingLeft(ray_angle) ? -1 : 1;
  // ver_inter->xstep *= (isRayFacingRight(ray_angle) && ver_inter->xstep < 0) ? -1 : 1;

  ver_inter->ystep = TILE_SIZE * tan(ray_angle);
  ver_inter->ystep *= (isRayFacingUp(ray_angle) && ver_inter->ystep > 0) ? -1 : 1;
  ver_inter->ystep *= (isRayFacingDown(ray_angle) && ver_inter->ystep < 0) ? -1 : 1;

  ver_inter->xToCheck = 0;
  ver_inter->yToCheck = 0;
  ver_inter->nextVertTouchX = ver_inter->xintercept;
  ver_inter->nextVertTouchY = ver_inter->yintercept;

}

void horizontal_intersection(t_game *game, t_hor_intersection *hor_inter, double ray_angle)
{

  init_horizontal_intersection(game, hor_inter, ray_angle);

  while (hor_inter->nextHorzTouchX >= 0 && hor_inter->nextHorzTouchX <= game->width 
    && hor_inter->nextHorzTouchY >= 0 && hor_inter->nextHorzTouchY <= game->height) 
    {
    hor_inter->xToCheck = hor_inter->nextHorzTouchX;
    hor_inter->yToCheck = hor_inter->nextHorzTouchY + (isRayFacingUp(ray_angle) ? -1 : 0);
    
    if (map_has_wall(game, hor_inter->xToCheck, hor_inter->yToCheck)) {
        // found a wall hit
        hor_inter->horzWallHitX = hor_inter->nextHorzTouchX;
        hor_inter->horzWallHitY = hor_inter->nextHorzTouchY;
        hor_inter->horzWallContent = game->map[(int)floor(hor_inter->yToCheck / TILE_SIZE)][(int)floor(hor_inter->xToCheck / TILE_SIZE)];
        hor_inter->foundHorzWallHit = true;
        break;
    } else {
        hor_inter->nextHorzTouchX += hor_inter->xstep;
        hor_inter->nextHorzTouchY += hor_inter->ystep;
    }
  }
}

void vertical_intersection(t_game *game, t_ver_intersection *ver_inter, double ray_angle)
{
    init_vertical_intersection(game, ver_inter, ray_angle);

    while (ver_inter->nextVertTouchX >= 0 && ver_inter->nextVertTouchX <= game->width && ver_inter->nextVertTouchY >= 0 && ver_inter->nextVertTouchY <= game->height) {
        ver_inter->xToCheck = ver_inter->nextVertTouchX + (isRayFacingLeft(ray_angle) ? -1 : 0);
        ver_inter->yToCheck = ver_inter->nextVertTouchY;
        
        if (map_has_wall(game, ver_inter->xToCheck, ver_inter->yToCheck)) {
            // found a wall hit
            ver_inter->vertWallHitX = ver_inter->nextVertTouchX;
            ver_inter->vertWallHitY = ver_inter->nextVertTouchY;
            ver_inter->vertWallContent = game->map[(int)floor(ver_inter->yToCheck / TILE_SIZE)][(int)floor(ver_inter->xToCheck / TILE_SIZE)];
            ver_inter->foundVertWallHit = true;
            break;
        } else {
            ver_inter->nextVertTouchX += ver_inter->xstep;
            ver_inter->nextVertTouchY += ver_inter->ystep;
        }
        
    }
}
