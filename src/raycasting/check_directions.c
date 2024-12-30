#include <raycasting.h>

int isRayFacingDown(double ray_angle)
{
  if(ray_angle > 0 && ray_angle < M_PI)
    return true;
  return false;
}

int isRayFacingUp(double ray_angle)
{
    if(ray_angle > 0 && ray_angle < M_PI)
        return false;
    return true;
}

int isRayFacingRight(double ray_angle)
{
    if(ray_angle < 0.5 * PI || ray_angle > 1.5 * PI)
        return true;
    return false;
}


int isRayFacingLeft(double ray_angle)
{
  if(ray_angle < 0.5 * PI || ray_angle > 1.5 * PI)
    return false;
return true;
}
