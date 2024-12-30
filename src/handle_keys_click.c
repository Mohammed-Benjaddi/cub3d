#include <cub3D.h>

void right_arrow(t_game *game)
{
  game->player.turn_direction = 1;
  game->player.rotation_angle += game->player.turn_direction * game->player.rotation_speed;
  // printf("---> %f <---\n", rad_to_deg(game->player.rotation_angle));
	game->player.move_step = game->player.walk_direction * game->player.move_speed;
	game->player.player_x += cos(game->player.rotation_angle) * game->player.move_step;
	game->player.player_y += sin(game->player.rotation_angle) * game->player.move_step;


  // game->minimap.p_x += cos(game->player.rotation_angle) * game->player.move_step;
	// game->minimap.p_y += sin(game->player.rotation_angle) * game->player.move_step;

}

void left_arrow(t_game *game)
{
  // angle = 2.144
  game->player.turn_direction = -1;
  game->player.rotation_angle += game->player.turn_direction * game->player.rotation_speed;
  // printf("---> %f <---\n", rad_to_deg(game->player.rotation_angle));
	game->player.move_step = game->player.walk_direction * game->player.move_speed;
	game->player.player_x += cos(game->player.rotation_angle) * game->player.move_step;
	game->player.player_y += sin(game->player.rotation_angle) * game->player.move_step;

  // game->minimap.p_x += cos(game->player.rotation_angle) * game->player.move_step;
	// game->minimap.p_y += sin(game->player.rotation_angle) * game->player.move_step;
	// game->minimap.p_x += cos(game->player.rotation_angle) * game->player.move_step;
	// game->minimap.p_y += sin(game->player.rotation_angle) * game->player.move_step;
}

bool player_can_move(t_game *game, double new_x, double new_y)
{
  int i;

  i = -2;
  int y = floor(new_y);
  int x = floor(new_x);
  while(i <= 2)
  {
    if ((y + i) / TILE_SIZE >= 0 && (y + i) / TILE_SIZE < (game->height / TILE_SIZE) 
      &&  (x / TILE_SIZE) >= 0 && (x / TILE_SIZE) < (game->width / TILE_SIZE)) {
      if(game->map[(y + i) / TILE_SIZE][x / TILE_SIZE] == '1')
        return false;
    }
    i++;
  }

  i = -2;
  while(i <= 2)
  {
    if (y / TILE_SIZE >= 0 && y / TILE_SIZE < (game->height / TILE_SIZE) 
      &&  (x + i) / TILE_SIZE >= 0 && (x + i) / TILE_SIZE < (game->width / TILE_SIZE)) {
      if(game->map[y / TILE_SIZE][(x + i) / TILE_SIZE] == '1')
        return false;
    }
    i++;
  }
  return true;
}

void w_key(t_game *game)
{
  double new_x;
  double new_y;
  double new_x_mm;
  double new_y_mm;

  new_x = game->player.player_x;
  new_y = game->player.player_y;
  game->player.walk_direction = 1;
  game->player.rotation_angle += game->player.turn_direction * game->player.rotation_speed;
	game->player.move_step = game->player.walk_direction * game->player.move_speed;
  new_x += cos(game->player.rotation_angle) * game->player.move_step;
	new_y += sin(game->player.rotation_angle) * game->player.move_step;
  if(!player_can_move(game, new_x, new_y))
    return;
  game->player.player_x = new_x;
  game->player.player_y = new_y;
  // =================================================
  new_x_mm =  game->minimap.p_x;
  new_y_mm =  game->minimap.p_y;
  new_x_mm += cos(game->player.rotation_angle) * cos(game->player.rotation_angle) * game->player.move_step;
	new_y_mm += sin(game->player.rotation_angle) * sin(game->player.rotation_angle) * game->player.move_step;
  // game->minimap.p_x = new_x_mm;
  // game->minimap.p_y = new_y_mm * 0.7; 
  // printf("x --> %f | y --> %f\n", game->minimap.p_x, game->minimap.p_y);
}

void s_key(t_game *game)
{
  double new_x;
  double new_y;
  double new_x_mm;
  double new_y_mm;

  new_x = game->player.player_x;
  new_y = game->player.player_y;
  game->player.walk_direction = -1;
  game->player.rotation_angle += game->player.turn_direction * game->player.rotation_speed;
	game->player.move_step = game->player.walk_direction * game->player.move_speed;
	new_x += cos(game->player.rotation_angle) * game->player.move_step;
	new_y += sin(game->player.rotation_angle) * game->player.move_step;
  if(!player_can_move(game, new_x, new_y))
    return;
  game->player.player_x = new_x;
  game->player.player_y = new_y;
  // =================================================
  new_x_mm =  game->minimap.p_x;
  new_y_mm =  game->minimap.p_y;
  new_x_mm += cos(game->player.rotation_angle) * game->player.move_step;
	new_y_mm += sin(game->player.rotation_angle) * game->player.move_step;
  game->minimap.p_x = new_x_mm;
  game->minimap.p_y = new_y_mm;
}

void a_key(t_game *game)
{
  double new_x;
  double new_y;
  double new_x_mm;
  double new_y_mm;

  new_x = game->player.player_x;
  new_y = game->player.player_y;

	game->player.walk_direction = 0;
  game->player.move_step = game->player.move_speed;
  new_x -= cos(game->player.rotation_angle + PI / 2) * game->player.move_step;
  new_y -= sin(game->player.rotation_angle + PI / 2) * game->player.move_step;
  if(!player_can_move(game, new_x, new_y))
    return;
  game->player.player_x = new_x;
  game->player.player_y = new_y;
  // =================================================
  new_x_mm =  game->minimap.p_x;
  new_y_mm =  game->minimap.p_y;
  new_x_mm -= cos(game->player.rotation_angle + PI / 2) * game->player.move_step;
	new_y_mm -= sin(game->player.rotation_angle + PI / 2) * game->player.move_step;

  game->minimap.p_x = new_x_mm;
  game->minimap.p_y = new_y_mm;
}

void d_key(t_game *game)
{
  double new_x;
  double new_y;
  double new_x_mm;
  double new_y_mm;

  new_x = game->player.player_x;
  new_y = game->player.player_y;

  game->player.walk_direction = 0;
  game->player.move_step = game->player.move_speed;
  new_x += cos(game->player.rotation_angle + PI / 2) * game->player.move_step;
  new_y += sin(game->player.rotation_angle + PI / 2) * game->player.move_step;
  if(!player_can_move(game, new_x, new_y))
    return;
  game->player.player_x = new_x;
  game->player.player_y = new_y;
  // =================================================
  new_x_mm =  game->minimap.p_x;
  new_y_mm =  game->minimap.p_y;
  new_x_mm += cos(game->player.rotation_angle + PI / 2) * game->player.move_step;
	new_y_mm += sin(game->player.rotation_angle + PI / 2) * game->player.move_step;
  
  game->minimap.p_x = new_x_mm;
  game->minimap.p_y = new_y_mm;
}
