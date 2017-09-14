/*
** box_dial.c for box_dial.c in /home/Ordrix0/techadventure
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Sat Apr 22 13:28:51 2017 Guillaume Barthe
** Last update Sat May 27 15:48:56 2017 Guillaume Barthe
*/

#include "../../all.h"

void    init_box_ok(sfVector2f pos[3], sfVector2f len[3])
{
  pos[0].x = 700;
  pos[0].y = 300;
  pos[1].x = 500;
  pos[1].y = 60;
  len[0].x = _WIDTH/2 - 350;
  len[0].y = _HEIGHT/2 - 250;
  len[1].x = _WIDTH/2 - 250;
  len[1].y = _HEIGHT/2 - 50;
}

int		box_err(sfRenderWindow* window, t_my_all *s_all, sfText* txt)
{
  sfVector2f	pos[2];
  sfVector2f	len[2];
  sfVector2i	m_pos;

  init_box_ok(pos, len);
  sfRenderWindow_clear(window, sfWhite);
  WRRectangle(len[0], pos[0], window, sfColor_fromRGB(0, 0, 0));
  WRRectangle(len[1], pos[1], window, sfColor_fromRGB(0, 255, 0));
  WRtexte(txt, _WIDTH/2 - 300, _HEIGHT/2 - 170, window);
  WRtexte(s_all->ok, _WIDTH/2 - 30, _HEIGHT/2 - 40, window);
  sfRenderWindow_display(window);
  my_sleep(1);
  while (1)
    {
      m_pos = sfMouse_getPosition(NULL);
      if (m_pos.x >= (_WIDTH/2 - 300) && m_pos.x <= (_WIDTH/2 + 200)    \
	  && m_pos.y >= (_HEIGHT/2 - 50) && m_pos.y <= (_HEIGHT/2 + 10))
	if (sfMouse_isButtonPressed(sfMouseLeft))
	  return (3);
    }
}
