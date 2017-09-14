/*
** disp.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Wed Apr 26 11:57:33 2017 Florian BORD
** Last update Wed May 24 11:40:17 2017 Florian BORD
*/

#include "../all.h"

void    disp_gm(la_struct pac)
{
  sfRenderWindow_clear(pac.window, sfBlack);
  sfRenderWindow_drawSprite(pac.window, pac.gm.back, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.gm.back2, NULL);
  pac = my_prog(pac);
  sfRenderWindow_drawSprite(pac.window, pac.gm.inlog, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.gm.log, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.gm.enem2, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.gm.enem1, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.gm.anim, NULL);
  sfRenderWindow_display(pac.window);
}

la_struct       scrol_log(la_struct pac)
{
  static float  stock = 0;

  sfSprite_setPosition(pac.gm.inlog, pac.gm.scale2);
  if (pac.gm.prog == 1)
    stock = 0;
  if (pac.gm.prog > stock)
    {
      stock = stock + 0.01;
      pac.gm.scale2.y = pac.gm.scale2.y - 0.2;
    }
  return (pac);
}

sfSprite        *anim_file(sfSprite *sprite)
{
  static sfVector2i     pos = {0, 144};
  sfIntRect             box;
  static int		loop = 0;

  box.left = pos.x;
  box.top = pos.y;
  box.width = 32;
  box.height = 42;
  if (pos.x >= 96 && loop == 20)
    {
      pos.x = 0;
      loop = 0;
    }
  sfSprite_setTextureRect(sprite, box);
  if (loop == 20)
    {
      pos.x = pos.x + 32;
      loop = 0;
    }
  loop++;
  return (sprite);
}

sfSprite        *anim_file_cor(sfSprite *sprite, int dir, la_struct pac)
{
  static sfVector2i     pos = {0, 0};
  sfIntRect             box;
  static int            tim = 0;

  pos.y = dir;
  box.left = pos.x;
  box.top = pos.y;
  box.width = 32;
  box.height = 42;
  sfSprite_setTextureRect(sprite, box);
  if (pos.x >= 96 && tim == 20)
    {
      pos.x = 0;
      tim = 0;
    }
  else if (tim == 20)
    {
      if (dir != 0)
	pos.x = pos.x + 32;
      else
	pos.x = 0;
      tim = 0;
    }
  tim++;
  return (sprite);
}

sfSprite	*anim_switch(sfSprite *sprite, int dir)
{
  sfIntRect	box;

  box.left = 0;
  box.top = dir;
  box.width = 500;
  box.height = 243;
  sfSprite_setTextureRect(sprite, box);
  return (sprite);
}
