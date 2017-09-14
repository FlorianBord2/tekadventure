/*
** shot2.c for  in /home/Neo/Graphical/tekadventure/florian
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Thu May 11 09:59:56 2017 Florian BORD
** Last update Mon May 22 16:35:02 2017 Florian BORD
*/

#include "../all.h"

la_struct	my_switch(la_struct pac)
{
  static int	i = 1;
  
  if (sfKeyboard_isKeyPressed(sfKeyE) == sfFalse && i == 1)
    i = 0;
  if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue && i == 0)
    {
      i = 1;
      if (pac.shot.where == 1 && pac.six.stat_1 == 0)
	pac.six.stat_1 = 1;
      else if (pac.shot.where == 1 && pac.six.stat_1 == 1)
	pac.six.stat_1 = 2;
      else if (pac.shot.where == 1 && pac.six.stat_1 == 2)
	pac.six.stat_1 = 0;
      if (pac.shot.where == 3 && pac.six.stat_2 == 0)
	pac.six.stat_2 = 1;
      else if (pac.shot.where == 3 && pac.six.stat_2 == 1)
	pac.six.stat_2 = 2;
      else if (pac.shot.where == 3 && pac.six.stat_2 == 2)
	pac.six.stat_2 = 0;
      if (pac.shot.where == 4 && pac.six.stat_3 == 0)
	pac.six.stat_3= 1;
      else if (pac.shot.where == 4 && pac.six.stat_3 == 1)
	pac.six.stat_3= 2;
      else if (pac.shot.where == 4 && pac.six.stat_3 == 2)
	pac.six.stat_3 = 0;
    }
  return (pac);
}

void	disp_check(la_struct pac)
{
  if (pac.shot.done != 0)
    {
      sfSprite_setPosition(pac.cor.check, pac.cor.door2_pos);
      sfRenderWindow_drawSprite(pac.window, pac.cor.check, NULL);
      sfRenderWindow_drawSprite(pac.window, pac.hud.cle, NULL);
    }
  if (pac.cor.hubdone == 1)
    {
      sfSprite_setPosition(pac.cor.check, pac.cor.door1_pos);
      sfRenderWindow_drawSprite(pac.window, pac.cor.check, NULL);
      sfRenderWindow_drawSprite(pac.window, pac.hud.pc, NULL);
    }
  if (pac.lvlcledone == 2)
    {
      sfSprite_setPosition(pac.cor.check, pac.cor.door3_pos);
      sfRenderWindow_drawSprite(pac.window, pac.cor.check, NULL);
      sfRenderWindow_drawSprite(pac.window, pac.hud.cle2, NULL);
    }
}

la_struct	dpl_graph2(la_struct pac)
{
  if (pac.shot.ppos.y < pac.shot.mouse.y)
    {
      pac.shot.ppos.y = pac.shot.ppos.y + DPL_COR;
      pac.shot.taille.x = pac.shot.taille.x + 0.05;
      pac.shot.taille.y = pac.shot.taille.y + 0.05;
    }
  if (pac.shot.ppos.y > pac.shot.mouse.y)
    {
      pac.shot.ppos.y = pac.shot.ppos.y - DPL_COR;
      pac.shot.taille.x = pac.shot.taille.x - 0.05;
      pac.shot.taille.y = pac.shot.taille.y - 0.05;
    }
  if (pac.shot.ppos.y == pac.shot.mouse.y &&
      pac.shot.ppos.x == pac.shot.mouse.x)
    sfMusic_stop(pac.sound.walk);
  return (pac);
}
