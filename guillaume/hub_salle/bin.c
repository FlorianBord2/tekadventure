/*
** bin.c for bin.c in /home/Ordrix0/techadventure
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Sat Apr 22 17:16:35 2017 Guillaume Barthe
** Last update Sat May 27 15:48:28 2017 Guillaume Barthe
*/

#include "../../all.h"

void	init_pos_boule(sfVector2f pos[6])
{
  pos[0].x = rand()%_WIDTH;
  pos[0].y = 2 * -616;
  pos[1].x = rand()%_WIDTH;
  pos[1].y = -600;
  pos[2].x = rand()%_WIDTH;
  pos[2].y = 2 * -600;
  pos[3].x = rand()%_WIDTH;
  pos[3].y = -600;
  pos[4].x = rand()%_WIDTH;
  pos[4].y = -600;
  pos[5].x = rand()%_WIDTH;
  pos[5].y = -600;
}

int		zone_boule(int i, sfVector2f pos[6], t_my_all *s_all, sfVector2i m_pos)
{
  static int	count = 0;
  if (pos[i].y > 1080)
    pos[i].y = -600;
  if (m_pos.x > pos[i].x && m_pos.x < pos[i].x + (0.3 * 640) && m_pos.y \
      > pos[i].y && m_pos.y < pos[i].y + (0.3 * 616))
    {
      if (sfMouse_isButtonPressed(sfMouseLeft))
	{
	  sfMusic_play(s_all->trash->b_papier);
	  sfMusic_setVolume(s_all->trash->b_papier, s_all->vol);
	  count = count + 1;
	  pos[i].x = -1000;
	  return (count);
	}
      WRSprite(s_all->trash->s_boule, pos[i].x, pos[i].y, s_all->ati);
      return (-2);
    }
  return (-1);
}
int		hit_trash(sfRenderWindow* window, t_my_all *s_all)
{
  sfVector2i    m_pos;
  sfVector2f	pos[6];
  int		i;
  int		count;

  init_pos_boule(pos);
  s_all->ati->scale_x = 0.3;
  s_all->ati->scale_y = 0.3;
  box_err(window, s_all, s_all->txt->code_found);
  while (1)
    {
      i = 0;
      m_pos = sfMouse_getPosition(NULL);
      sfRenderWindow_clear(window, sfWhite);
      while (i < 6)
	{
	  if ((count = zone_boule(i, pos, s_all, m_pos)) == 5)
	    return (3);
	  if (count != -2)
	    WRSprite(s_all->trash->boule, pos[i].x, pos[i].y, s_all->ati);
	  pos[i].y = pos[i].y + 0.3;
	  i = i + 1;
	}
      sfRenderWindow_display(window);
    }
}

int		get_code(sfRenderWindow* window, t_my_all *s_all)
{
  sfRenderWindow_clear(window, sfWhite);
  box_err(window, s_all, s_all->txt->code_win);
  return (0);
}

int		hit_box_bin(sfRenderWindow* window, t_my_all *s_all)
{
  sfVector2i	m_pos;
  int		i;

  i = 0;
  m_pos = sfMouse_getPosition(NULL);
  if (m_pos.x > 1433 && m_pos.x < 1520 && m_pos.y > 650 && m_pos.y < 670)
    i = 1;
  else if (m_pos.x > 1386 && m_pos.x < 1564 && m_pos.y > 706 && m_pos.y < 888)
    i = 1;
  else if (m_pos.x > 1375 && m_pos.x < 1578 && m_pos.y > 670 && m_pos.y < 706)
    i = 1;
  if (i == 1)
    {
      WRSprite(s_all->hub->s_bin, 1350, 650, s_all->ati);
      if (sfMouse_isButtonPressed(sfMouseLeft))
	if (box_hub(window, s_all, s_all->txt->bin) == 3)
	  {
	    hit_trash(window, s_all);
	    sfMusic_destroy(s_all->trash->b_papier);
	    get_code(window, s_all);
	    return (1);
	  }
    }
  return (0);
}
