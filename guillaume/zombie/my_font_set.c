/*
** my_font_set.c for my_font_set.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/zombie
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Sat May 27 16:10:02 2017 Guillaume Barthe
** Last update Sat May 27 16:11:04 2017 Guillaume Barthe
*/

#include "../../all.h"

int	set_zombie(t_my_zon *s_zon, sfRenderWindow *window, int zon)
{
  if (zon == 0)
    {
      if (zombie_spawn(s_zon, window) == 1)
	zon = 1;
    }
  else if (zon == 1)
    zombie_depla(s_zon, window);
  else if (zon == 3)
    {
      if (zombie_death(s_zon, window) == 1)
	{
	  s_zon->nb_zon = s_zon->nb_zon - 1;
	  zon = 4;
	}
    }
  return (zon);
}

void	set_font(sfRenderWindow* window, t_my_zon *s_zon)
{
  float	x;
  float	y;

  if (s_zon->pos->font.x <= -1920)
    s_zon->pos->font.x = -1920;
  x = s_zon->pos->font.x;
  y = s_zon->pos->font.y;
  WRSprite_window(s_zon->font, 0, 0, window);
  WRSprite_window(s_zon->t_build, (0.3 * x), y, window);
  WRSprite_window(s_zon->f_build, (0.4 * x), y, window);
  WRSprite_window(s_zon->s_build, (0.5 * x), y, window);
  WRSprite_window(s_zon->t_build, (0.3 * x) + 1920, y, window);
  WRSprite_window(s_zon->f_build, (0.4 * x) + 1920, y, window);
  WRSprite_window(s_zon->s_build, (0.5 * x) + 1920, y, window);
  WRSprite_window(s_zon->pise, x - 100, _HEIGHT/2 - 160, window);
  WRSprite_window(s_zon->terre, x + 1920, y, window);
  WRSprite_window(s_zon->terre, x, y, window);
  WRSprite_window(s_zon->sun, 0, 0, window);
}

void		walk_perso(t_my_zon *s_zon, sfRenderWindow *window)
{
  static int	dir = 96;
  int		my_dir;

  if ((my_dir = left_walk(s_zon, dir)) != dir)
    dir = my_dir;
  else if ((my_dir = right_walk(s_zon, dir)) != dir)
    dir = my_dir;
  else
    anim_car(s_zon->perso, dir, 1);
  WRSprite_window(s_zon->perso, s_zon->pos->perso.x, \
		  s_zon->pos->perso.y, window);
}
