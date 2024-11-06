#include <raycasting.h>

bool is_player(char c)
{
  if(c == 'N' || c == 'S' || c == 'E' || c == 'W')
    return true;
  return false;
}

void update_direction_dda(t_game *game) // update player direction using dda algo
{
  game->n_px  = game->player_x + cos(game->rotation_angle) * 30;
  game->n_py = game->player_y + sin(game->rotation_angle) * 30;
  double dx;
  double dy;
  dx = game->n_px - game->player_x;
  dy = game->n_py - game->player_y;
  double steps;
  if(fabs(dx) > fabs(dy))
    steps = fabs(dx);
  else
    steps = fabs(dy);
  int i;
  double x = game->player_x + 15;
  double y = game->player_y + 15;
  double x_inc = dx / steps;
  double y_inc = dy / steps;
  i = 0;
  while(i <= steps + 20)
  {
    ft_put_pixel(game->img, roundf(x), roundf(y), RED);
    x += x_inc;
    y += y_inc;
    i++;    
  }
}

void set_player_position(t_game *game)
{
	int i;
	int j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if(is_player(game->map[i][j]))
			{
				game->player_x = (j * 30);
				game->player_y = (i * 30);
				return;
			}
			j++;
		}
		i++;
	}
}

void put_player(t_game *game)
{
  int i;
  int j;

  i = 0;
  j = 0;
  
  while(i < 30)
  {
    j = 0;
    while (j < 30)
    {
      if(j >= 12 && j <= 18 && i >= 12 && i <= 18)
        ft_put_pixel(game->img, game->player_x + j, game->player_y + i, RED);
      j++;
    }
    i++;
  }
  update_direction_dda(game);
}
