/*
** t_set.c for t_set.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/hub_salle
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Thu May  4 13:55:24 2017 Guillaume Barthe
** Last update Thu May  4 15:32:25 2017 Guillaume Barthe
*/

#include "../../all.h"

void	set_clavier(t_my_all* s_all, int img)
{
  if (img == 0)
    WRSprite(s_all->elem->clavier, _WIDTH/2 - 825, _HEIGHT/2 - 325, s_all->ati);
  else if (img == 1)
    WRSprite(s_all->elem->t_c, _WIDTH/2 - 825, _HEIGHT/2 - 325, s_all->ati);
  else if (img == 2)
    WRSprite(s_all->elem->r_c, _WIDTH/2 - 825, _HEIGHT/2 - 325, s_all->ati);
  else if (img == 3)
    WRSprite(s_all->elem->o_c, _WIDTH/2 - 825, _HEIGHT/2 - 325, s_all->ati);
  else if (img == 4)
    WRSprite(s_all->elem->l_c, _WIDTH/2 - 825, _HEIGHT/2 - 325, s_all->ati);
}

int	disp_code(t_my_all *s_all, sfRenderWindow* window, int img, int i)
{
  int	ans;

  sfRenderWindow_clear(window, sfWhite);
  s_all->ati->scale_x = 0.5;
  s_all->ati->scale_y = 0.5;
  set_clavier(s_all, img);
  ans = answer(i, window);
  return (ans);
}
