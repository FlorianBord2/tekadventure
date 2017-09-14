/*
** zombie.c for zombie.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/zombie
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Wed May 17 13:32:53 2017 Guillaume Barthe
** Last update Fri May 26 12:40:05 2017 Guillaume Barthe
*/

#include "../../all.h"

int		zombie_death(t_my_zon *s_zon, sfRenderWindow* window)
{
  sfVector2f	ori;

  ori.x = 19;
  ori.y = 0;
  my_z_death(s_zon->zombie, 74, s_zon);
  sfSprite_setOrigin(s_zon->zombie, ori);
  WRSprite_window(s_zon->zombie, s_zon->pos->x_zon + s_zon->pos->font.x, \
		  _HEIGHT/2 + 100, window);
  if (s_zon->spawn == 3)
    return (1);
  else
    return (0);
}

void		re_depla(t_my_zon *s_zon)
{
  sfVector2f	d_pos;

  d_pos.x = s_zon->pos->x_zon + s_zon->pos->font.x;
  d_pos.y = s_zon->pos->perso.x;
  if ((d_pos.x - (d_pos.y + 120)) > 0)
    {
      s_zon->direction = 3;
      s_zon->pos->x_zon = s_zon->pos->x_zon - 2;
    }
  else if ((d_pos.x - (d_pos.y - 20)) < 0)
    {
      s_zon->direction = -3;
      s_zon->pos->x_zon = s_zon->pos->x_zon + 2;
    }
  else
    s_zon->life = s_zon->life - 0.3;
}

int		zombie_depla(t_my_zon *s_zon, sfRenderWindow *window)
{
  sfVector2f	scale;
  sfVector2f	ori;


  ori.x = 19;
  ori.y = 0;
  re_depla(s_zon);
  scale.x = s_zon->direction;
  scale.y = 3;
  z_get_depla(s_zon->zombie, 0, s_zon);
  sfSprite_setOrigin(s_zon->zombie, ori);
  sfSprite_setScale(s_zon->zombie, scale);
  //  sfMusic_play(s_zon->ruit);
  WRSprite_window(s_zon->zombie, s_zon->pos->x_zon + s_zon->pos->font.x, \
		  _HEIGHT/2 + 100, window);
  return (1);
}

int		zombie_spawn(t_my_zon *s_zon, sfRenderWindow *window)
{
  sfVector2f	scale;
  sfVector2f	ori;

  scale.x = 3;
  scale.y = 3;
  ori.x = 19;
  ori.y = 0;
  z_get_sprite(s_zon->zombie, 74, s_zon);
  sfSprite_setOrigin(s_zon->zombie, ori);
  sfSprite_setScale(s_zon->zombie, scale);
  WRSprite_window(s_zon->zombie, s_zon->pos->x_zon + s_zon->pos->font.x, \
		  _HEIGHT/2 + 100, window);
  if (s_zon->spawn == 1)
    return (1);
  else
    return (0);
}
