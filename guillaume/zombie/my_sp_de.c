/*
** my_sp_de.c for my_sp_de.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/zombie
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Tue May 16 12:45:01 2017 Guillaume Barthe
** Last update Mon May 22 16:27:55 2017 Guillaume Barthe
*/

#include "../../all.h"

sfSprite		*my_z_death(sfSprite *sprite, int dir, t_my_zon *s_zon)
{
  sfIntRect		box;
  static int	        frame = 0;

  box.left = s_zon->pos->pos_spawn.y;
  box.top = dir;
  box.width = 38;
  box.height = 74;
  sfSprite_setTextureRect(sprite, box);
  if (s_zon->pos->pos_spawn.y >= 410)
    {
      s_zon->spawn = 3;
      s_zon->pos->pos_spawn.y = 210;
    }
  else if (frame == 20)
    {
      frame = 0;
      s_zon->pos->pos_spawn.y = s_zon->pos->pos_spawn.y + 39;
    }
  frame++;
  return (sprite);
}

sfSprite		*z_get_depla(sfSprite *sprite, int dir, t_my_zon *s_zon)
{
  static sfVector2i	pos = {38, 0};
  sfIntRect		box;
  static int		frame = 0;

  pos.y = dir;
  box.left = pos.x;
  box.top = pos.y;
  box.width = 38;
  box.height = 74;
  sfSprite_setTextureRect(sprite, box);
  if (pos.x >= 311)
    {
      s_zon->spawn = 0;
      pos.x = 38;
    }
  else if (frame == 30)
    {
      frame = 0;
      pos.x = pos.x + 39;
    }
  frame++;
  return (sprite);
}

sfSprite		*z_get_sprite(sfSprite *sprite, int dir, t_my_zon *s_zon)
{
  sfIntRect		box;
  static int	        frame = 0;

  box.left = s_zon->pos->pos_spawn.x;
  box.top = dir;
  box.width = 39;
  box.height = 74;
  sfSprite_setTextureRect(sprite, box);
  if (s_zon->pos->pos_spawn.x >= 200)
    {
      s_zon->spawn = 1;
      s_zon->pos->pos_spawn.x = 0;
    }
  else if (frame == 20)
    {
      frame = 0;
      if (dir != 0)
        s_zon->pos->pos_spawn.x = s_zon->pos->pos_spawn.x + 41;
      else
        s_zon->pos->pos_spawn.x = 0;
    }
  frame++;
  return (sprite);
}

sfSprite		*anim_perso(sfSprite *sprite, int dir, int depla)
{
  static sfVector2i	pos = {0, 0};
  sfIntRect		box;
  static int	        frame = 0;

  pos.y = dir;
  box.left = pos.x;
  box.top = pos.y;
  box.width = 32;
  box.height = 42;
  sfSprite_setTextureRect(sprite, box);
  if (pos.x >= 96)
    {
      pos.x = 0;
    }
  else if (frame == 20)
    {
      frame = 0;
      if (dir != 0 && depla == 0)
	pos.x = pos.x + 32;
      else
	pos.x = 0;
    }
  frame++;
  return (sprite);
}
