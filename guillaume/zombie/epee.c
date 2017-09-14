/*
** epee.c for epee.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/zombie
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Tue May 16 18:50:04 2017 Guillaume Barthe
** Last update Sat May 27 16:07:07 2017 Guillaume Barthe
*/

#include "../../all.h"

void		oh_my_hit(t_my_zon *s_zon, sfRenderWindow *window)
{
  WRSprite_window(s_zon->epee_h, s_zon->pos->perso.x - 25, \
		  s_zon->pos->perso.y + 68, window);
  if ((s_zon->pos->x_zon + s_zon->pos->font.x) >= \
      (s_zon->pos->perso.x - 25 - 50) && \
      (s_zon->pos->x_zon + s_zon->pos->font.x) <= \
      (s_zon->pos->perso.x - 25 + s_zon->pos->taille_epee_h.y))
    {
      if (s_zon->epee_count <= 60)
	{
	  s_zon->hit = s_zon->hit + 3;
	  s_zon->pos->x_zon = s_zon->pos->x_zon - 3;
	}
    }
}

void		hit_my_zombie(t_my_zon *s_zon, sfRenderWindow *window)
{
  if (s_zon->pos->direction_epee == 0)
    {
      WRSprite_window(s_zon->epee_h, s_zon->pos->perso.x + 35, \
		      s_zon->pos->perso.y + 68, window);
      if ((s_zon->pos->x_zon + s_zon->pos->font.x) >= \
	  (s_zon->pos->perso.x + 35) && \
	  (s_zon->pos->x_zon + s_zon->pos->font.x) <= \
	  (s_zon->pos->perso.x + 35 + \
	   s_zon->pos->taille_epee_h.y) + 50)
	{
	  if (s_zon->epee_count <= 60)
	    {
	      s_zon->hit = s_zon->hit + 3;
	      s_zon->pos->x_zon = s_zon->pos->x_zon + 3;
	    }
	}
    }
  else
    {
      oh_my_hit(s_zon, window);
    }
}

void		draw_epee_h(t_my_zon *s_zon, sfRenderWindow *window)
{
  sfIntRect	rect;
  sfVector2f	scale;

  scale.x = 0.7;
  scale.y = 0.7;
  if (s_zon->pos->direction_epee == 1)
    rect.left = 0;
  else
    rect.left = 241;
  rect.top = 0;
  rect.width = s_zon->pos->taille_epee_h.x;
  rect.height = s_zon->pos->taille_epee_h.y;
  sfSprite_setTextureRect(s_zon->epee_h, rect);
  sfSprite_setScale(s_zon->epee_h, scale);
  hit_my_zombie(s_zon, window);
}

void		draw_epee_n(t_my_zon *s_zon, sfRenderWindow *window)
{
  sfIntRect	rect;
  sfVector2f	scale;

  scale.x = 0.7;
  scale.y = 0.7;
  if (s_zon->pos->direction_epee == 0)
    rect.left = 0;
  else
    rect.left = s_zon->pos->taille_epee_n.y;
  rect.top = 0;
  rect.width = s_zon->pos->taille_epee_n.x;
  rect.height = s_zon->pos->taille_epee_n.y;
  sfSprite_setTextureRect(s_zon->epee_n, rect);
  sfSprite_setScale(s_zon->epee_n, scale);
  if (s_zon->pos->direction_epee == 0)
    WRSprite_window(s_zon->epee_n, s_zon->pos->perso.x + 30, \
		    s_zon->pos->perso.y + 35, window);
  else
    WRSprite_window(s_zon->epee_n, s_zon->pos->perso.x - 15, \
		    s_zon->pos->perso.y + 35, window);
}
