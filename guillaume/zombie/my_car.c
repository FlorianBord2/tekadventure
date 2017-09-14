/*
** my_car.c for my_car.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/zombie
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Wed May 17 14:17:06 2017 Guillaume Barthe
** Last update Tue May 23 13:39:13 2017 Guillaume Barthe
*/

#include "../../all.h"

int		my_life(t_my_zon *s_zon, sfRenderWindow *window)
{
  sfIntRect	rect;

  rect.left = 0;
  rect.top = 0;
  rect.width = s_zon->life;
  rect.height = 30;
  sfSprite_setTextureRect(s_zon->b_life, rect);
  WRSprite_window(s_zon->b_life, _WIDTH/2 - 50, 200, window);
  return (0);
}

void		anim_car(sfSprite* perso, int dir, int depla)
{
  sfVector2f	scale;

  scale.x = 3;
  scale.y = 3;
  sfSprite_setScale(perso, scale);
  anim_perso(perso, dir, depla);
}

int	left_walk(t_my_zon *s_zon, int dir)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft))
    {
      s_zon->pos->direction_epee = 1;
      dir = 48;
      anim_car(s_zon->perso, 48, 0);
      if (s_zon->pos->font.x == 0 || s_zon->pos->perso.x > _WIDTH/2)
	{
	  if (s_zon->pos->perso.x > 0)
	    s_zon->pos->perso.x = s_zon->pos->perso.x - 6;
	}
      else
	s_zon->pos->font.x = s_zon->pos->font.x + 6;
    }
  return (dir);
}

int	right_walk(t_my_zon *s_zon, int dir)
{
  if (sfKeyboard_isKeyPressed(sfKeyRight))
    {
      s_zon->pos->direction_epee = 0;
      dir = 96;
      anim_car(s_zon->perso, 96, 0);
      if (s_zon->pos->perso.x < _WIDTH/2 || s_zon->pos->font.x == -1920)
	{
	  if (s_zon->pos->perso.x < 1824)
	    s_zon->pos->perso.x = s_zon->pos->perso.x + 6;
	}
      else
	s_zon->pos->font.x = s_zon->pos->font.x - 6;
    }
  return (dir);
}
