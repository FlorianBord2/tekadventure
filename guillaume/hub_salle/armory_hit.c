/*
** armory_hit.c for armory_hit.c in /home/Ordrix0/techadventure
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Thu Apr 20 15:57:18 2017 Guillaume Barthe
** Last update Mon May 22 14:50:38 2017 Guillaume Barthe
*/

#include "../../all.h"

void	init_vect_cube(sfVector2f pos[10])
{
  int	WIDTH;
  int	HEIGHT;

  WIDTH = 1700;
  HEIGHT = 900;
  pos[0].x = rand()%WIDTH;
  pos[0].y = rand()%HEIGHT;
  pos[1].x = rand()%WIDTH;
  pos[1].y = rand()%HEIGHT;
  pos[2].x = rand()%WIDTH;
  pos[2].y = rand()%HEIGHT;
  pos[3].x = rand()%WIDTH;
  pos[3].y = rand()%HEIGHT;
  pos[4].x = rand()%WIDTH;
  pos[4].y = rand()%HEIGHT;
  pos[5].x = rand()%WIDTH;
  pos[5].y = rand()%HEIGHT;
  pos[6].x = rand()%WIDTH;
  pos[6].y = rand()%HEIGHT;
  pos[7].x = rand()%WIDTH;
  pos[7].y = rand()%HEIGHT;
  pos[8].x = rand()%WIDTH;
  pos[8].y = rand()%HEIGHT;
  pos[9].x = rand()%WIDTH;
  pos[9].y = rand()%HEIGHT;
}

int             hit_inte_armo(t_my_all *s_all, sfRenderWindow* window)
{
  sfVector2i	m_pos;
  int		i;
  static int	time = 0;

  m_pos = sfMouse_getPosition(NULL);
  i = 0;
  if (m_pos.x > 290 && m_pos.x < 675 && m_pos.y > 820 && m_pos.y < 1056)
    {
      s_all->ati->scale_x = 0.3;
      s_all->ati->scale_y = 0.3;
      WRSprite(s_all->elem->s_ordi, 200, 800, s_all->ati);
      if (sfMouse_isButtonPressed(sfMouseLeft))
	{
	  i = fct_code(s_all, window, time);
	  time = time + 1;
	}
      if (i == 3)
	{
	  box_err(window, s_all, s_all->txt->unlock);
	  return (3);
	}
    }
  return (1);
}

int	draw_armory(sfVector2f cube[10], t_my_all *s_all, sfVector2f pos[10])
{
  int	i;

  i = 0;
  while (i <= 10)
    {
      s_all->ati->scale_x = 0.3;
      s_all->ati->scale_y = 0.3;
      WRSprite(s_all->elem->ordi, pos[i].x, pos[i].y, s_all->ati);
      s_all->ati->scale_x = 1.2;
      s_all->ati->scale_y = 1.2;
      WRSprite(s_all->elem->cube, cube[i].x, cube[i].y, s_all->ati);
      i = i + 1;
    }
  s_all->ati->scale_x = 0.3;
  s_all->ati->scale_y = 0.3;
  WRSprite(s_all->elem->ordi, 200, 800, s_all->ati);
  return (1);
}

int		s_scene(sfRenderWindow* window, t_my_all *s_all)
{
  sfVector2f	pos[10];
  sfVector2f	cube[10];

  init_vect_cube(pos);
  init_vect_cube(cube);
  box_err(window, s_all, s_all->txt->find_comp);
  while (1)
    {
      sfRenderWindow_clear(window, sfWhite);
      draw_armory(cube, s_all, pos);
      if (hit_inte_armo(s_all, window) == 3)
	return (3);
      sfRenderWindow_display(window);
      if (sfKeyboard_isKeyPressed(sfKeyEscape))
	return (0);
    }
}

int		hitbox_armory(sfRenderWindow* window, t_my_all *s_all)
{
  sfVector2i	m_pos;
  sfColor	color_pos;

  m_pos = sfMouse_getPosition(NULL);
  s_all->ati->scale_x = 0.5;
  s_all->ati->scale_y = 0.5;
  if (m_pos.x > 935 && m_pos.x < 1100 && m_pos.y > 415 && m_pos.y < 607)
    {
      color_pos = sfImage_getPixel(s_all->hub->img, m_pos.x, m_pos.y);
      if (color_pos.r == 255 && color_pos.g == 255 && color_pos.b == 255)
	WRSprite(s_all->hub->s_armory, 869, _HEIGHT/2 - 140, s_all->ati);
      if (sfMouse_isButtonPressed(sfMouseLeft))
        if (box_hub(window, s_all, s_all->txt->s_txt) == 3)
	  {
	    if (s_scene(window, s_all) == 3)
	      s_all->elem->code_un = 1;
	    my_sleep(1);
	  }
    }
  return (1);
}
