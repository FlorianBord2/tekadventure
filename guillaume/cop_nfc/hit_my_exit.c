/*
** hit_my_exit.c for hit_my_exit.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/cop_nfc
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Mon May 15 14:39:26 2017 Guillaume Barthe
** Last update Sat May 27 15:41:54 2017 Guillaume Barthe
*/

#include "../../all.h"

int	hit_my_exit(t_my_all *s_all)
{
  sfVector2i	m_pos;
  sfColor	color_pos;

  m_pos = sfMouse_getPosition(NULL);
  WRSprite(s_all->salle->exit, 1700, 50, s_all->ati);
  if (m_pos.x > 1700 && m_pos.y > 50)
    {
      color_pos = sfImage_getPixel(s_all->salle->img_exit, \
				   m_pos.x - 1700, m_pos.y - 50);
      if (color_pos.r == 38 && color_pos.g == 185 && color_pos.b == 154)
        if (sfMouse_isButtonPressed(sfMouseLeft))
	  return (3);
    }
  return (1);
}
