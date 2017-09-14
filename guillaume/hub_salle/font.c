/*
** font.c for font.c in /home/Ordrix0/scroller
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Fri Mar 31 20:45:10 2017 Guillaume Barthe
** Last update Sat May 27 15:56:22 2017 Guillaume Barthe
*/

#include "../../all.h"

int		hit_box_hub(t_my_all *s_all, sfRenderWindow* window)
{
  sfVector2i	m_pos;
  sfColor	color_pos;

  m_pos = sfMouse_getPosition(NULL);
  if (m_pos.x > 417 && m_pos.x < 856 && m_pos.y > 379 && m_pos.y < 625)
    {
      color_pos = sfImage_getPixel(s_all->hub->img, m_pos.x, m_pos.y);
      if (color_pos.r == 255 && color_pos.g == 255 && color_pos.b == 255)
	WRSprite(s_all->hub->f_block, 415, 375, s_all->ati);
      if (sfMouse_isButtonPressed(sfMouseLeft))
	if (box_hub(window, s_all, s_all->txt->txt) == 3)
	  return (0);
    }
  return (1);
}

int		move_pers(t_my_all *s_all, sfRenderWindow* window)
{
  s_all->ati->window = window;
  WRSprite(s_all->hub->wall, 0, 0, s_all->ati);
  s_all->ati->scale_x = 0.5;
  s_all->ati->scale_y = 0.5;
  WRSprite(s_all->hub->armory, 869, _HEIGHT/2 - 140, s_all->ati);
  WRSprite(s_all->hub->table, 610, _HEIGHT/2 + 150, s_all->ati);
  WRSprite(s_all->hub->table, 200, _HEIGHT/2 + 200, s_all->ati);
  s_all->ati->scale_x = 0.1;
  s_all->ati->scale_y = 0.1;
  WRSprite(s_all->hub->logo, 200, _HEIGHT/2 - 130, s_all->ati);
  WRSprite(s_all->elem->ordi, 700, _HEIGHT/2 + 110, s_all->ati);
  s_all->ati->scale_x = 1;
  s_all->ati->scale_y = 1;
  WRSprite(s_all->hub->bin, 1350, 650, s_all->ati);
  WRSprite(s_all->hub->canap, 1200, _HEIGHT/2 - 100, s_all->ati);
  if (hit_box_bin(window, s_all) == 1)
    my_sleep(1);
  if (hit_box_hub(s_all, window) == 0)
      return (0);
  hitbox_armory(window, s_all);
  s_all->ati->scale_x = 1;
  s_all->ati->scale_y = 1;
  return (1);
}

int	remp(t_my_all *s_all, t_data *data)
{
  if ((!(s_all->ati = malloc(sizeof (t_my_ati)))) ||		\
      (!(s_all->hub = malloc(sizeof (t_my_hub)))) ||		\
      (!(s_all->elem = malloc(sizeof (t_my_elem)))) ||		\
      (!(s_all->txt = malloc(sizeof (t_my_txt)))) ||		\
       (!(s_all->trash = malloc(sizeof (t_my_trash)))))
    return (84);
  s_all->ati->color = sfColor_fromRGB(27, 23, 173);
  s_all->ati->scale_x = 1;
  s_all->ati->scale_y = 1;
  hub_rp(s_all, data);
  txt_rp(s_all);
  elem_rp(s_all, data);
  trash_rp(s_all, data);
  s_all->my_last = LdSprite("./guillaume/zombie/img/final.png", 0);
  s_all->bt_y = LdTxt("Oui", "./guillaume/yes.ttf");
  s_all->bt_n = LdTxt("Non", "./guillaume/yes.ttf");
  s_all->ok = LdTxt("Ok", "./guillaume/yes.ttf");
}
