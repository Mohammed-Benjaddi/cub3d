#include <cub3D.h>

bool map_has_wall(t_game *game, double x, double y) {
    if (x < 0 || x > 720 || y < 0 || y > 420) 
        return true;
    int map_x = floor(x / TILE_SIZE);
    int map_y = floor(y / TILE_SIZE);
    return game->map[map_y][map_x] == '1';
}

void get_first_hor_inter(t_game *game, t_hor_intersection *hor_inter, double ray_angle) 
{
  hor_inter->yintercept = floor(game->player.player_y / TILE_SIZE) * TILE_SIZE;
  if(isRayFacingDown(ray_angle))
    hor_inter->yintercept += TILE_SIZE;
  else
    hor_inter->yintercept += 0;
  hor_inter->xintercept = game->player.player_x + (hor_inter->yintercept - game->player.player_y) / tan(ray_angle);
}

void init_horizontal_intersection(t_game *game, t_hor_intersection *hor_inter, double ray_angle)
{
  hor_inter->foundHorzWallHit = false;
  hor_inter->horzWallContent = 0;
  hor_inter->horzWallHitX = 0;
  hor_inter->horzWallHitY = 0;
  get_first_hor_inter(game, hor_inter, ray_angle);
  hor_inter->ystep = TILE_SIZE;
  if(isRayFacingUp(ray_angle))
    hor_inter->ystep *= -1;
  else
    hor_inter->ystep *= 1;
  hor_inter->xstep = TILE_SIZE / tan(ray_angle);
  if(isRayFacingLeft(ray_angle) && hor_inter->xstep > 0)
    hor_inter->xstep *= -1;
  else
    hor_inter->xstep *= 1;
  if(isRayFacingRight(ray_angle) && hor_inter->xstep < 0)
    hor_inter->xstep *= -1;
  else
    hor_inter->xstep *= 1;
  hor_inter->xToCheck = 0;
  hor_inter->yToCheck = 0;
  hor_inter->nextHorzTouchX = hor_inter->xintercept;
  hor_inter->nextHorzTouchY = hor_inter->yintercept;
}

void get_first_ver_inter(t_game *game, t_ver_intersection *ver_inter, double ray_angle) 
{
  ver_inter->xintercept = floor(game->player.player_x / TILE_SIZE) * TILE_SIZE;
  if(isRayFacingRight(ray_angle))
    ver_inter->xintercept += TILE_SIZE;
  else 
    ver_inter->xintercept += 0;
  ver_inter->yintercept =  game->player.player_y + (ver_inter->xintercept - game->player.player_x) * tan(ray_angle);
}


void init_vertical_intersection(t_game *game, t_ver_intersection *ver_inter, double ray_angle)
{
  ver_inter->foundVertWallHit = false;
  ver_inter->vertWallContent = 0;
  ver_inter->vertWallHitX = 0;
  ver_inter->vertWallHitY = 0;
  get_first_ver_inter(game, ver_inter, ray_angle);
  ver_inter->xstep = TILE_SIZE;
  if(isRayFacingLeft(ray_angle))
    ver_inter->xstep *= -1;
  else
    ver_inter->xstep *= 1;
  ver_inter->ystep = TILE_SIZE * tan(ray_angle);
  if(isRayFacingUp(ray_angle) && ver_inter->ystep > 0)
    ver_inter->ystep *= -1;
  else
    ver_inter->ystep *= 1;
  if(isRayFacingDown(ray_angle) && ver_inter->ystep < 0)
    ver_inter->ystep *= -1;
  else
    ver_inter->ystep *= 1;
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
    if(isRayFacingUp(ray_angle))
      hor_inter->yToCheck = hor_inter->nextHorzTouchY + -1;
    else
      hor_inter->yToCheck = hor_inter->nextHorzTouchY + 0;
    if (map_has_wall(game, hor_inter->xToCheck, hor_inter->yToCheck)) 
    {
        hor_inter->horzWallHitX = hor_inter->nextHorzTouchX;
        hor_inter->horzWallHitY = hor_inter->nextHorzTouchY;
        hor_inter->horzWallContent = game->map[(int)floor(hor_inter->yToCheck / TILE_SIZE)][(int)floor(hor_inter->xToCheck / TILE_SIZE)];
        hor_inter->foundHorzWallHit = true;
        break;
    } 
    else 
    {
        hor_inter->nextHorzTouchX += hor_inter->xstep;
        hor_inter->nextHorzTouchY += hor_inter->ystep;
    }
  }
}

void vertical_intersection(t_game *game, t_ver_intersection *ver_inter, double ray_angle)
{
    init_vertical_intersection(game, ver_inter, ray_angle);
    while (ver_inter->nextVertTouchX >= 0 && ver_inter->nextVertTouchX <= game->width 
      && ver_inter->nextVertTouchY >= 0 && ver_inter->nextVertTouchY <= game->height) 
      {
        if(isRayFacingLeft(ray_angle))
          ver_inter->xToCheck = ver_inter->nextVertTouchX + -1;
        else
          ver_inter->xToCheck = ver_inter->nextVertTouchX + 0;
        ver_inter->yToCheck = ver_inter->nextVertTouchY;
        if (map_has_wall(game, ver_inter->xToCheck, ver_inter->yToCheck)) 
        {
            ver_inter->vertWallHitX = ver_inter->nextVertTouchX;
            ver_inter->vertWallHitY = ver_inter->nextVertTouchY;
            ver_inter->vertWallContent = game->map[(int)floor(ver_inter->yToCheck / TILE_SIZE)][(int)floor(ver_inter->xToCheck / TILE_SIZE)];
            ver_inter->foundVertWallHit = true;
            break;
        }
        else 
        {
            ver_inter->nextVertTouchX += ver_inter->xstep;
            ver_inter->nextVertTouchY += ver_inter->ystep;
        }
    }
}
