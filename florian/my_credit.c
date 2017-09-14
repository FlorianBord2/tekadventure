/*
** my_credit.c for  in /home/Neo/Graphical/tekadventure/florian
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Wed May 17 10:09:54 2017 Florian BORD
** Last update Sun May 28 18:23:56 2017 Florian BORD
*/

#include "../all.h"

void	my_credit(la_struct pac)
{
  pac.cred.gui = my_text("Guillaume Barthe", pac.cred.ttf, pac.cred.gui);
  pac.cred.flo = my_text("Florian Bord", pac.cred.ttf, pac.cred.flo);
  pac.cred.hug = my_text("Hugo picquet", pac.cred.ttf, pac.cred.hug);
  pac.cred.leo = my_text("Leo Pechin", pac.cred.ttf, pac.cred.leo);
  while (pac.cred.hpos.y > -100)
    {
      sfRenderWindow_clear(pac.window, sfBlack);
      pac.cred = my_anim_text(pac.cred);
      sfRenderWindow_drawSprite(pac.window, pac.cred.back, NULL);
      sfRenderWindow_drawText(pac.window, pac.cred.gui, NULL);
      sfRenderWindow_drawText(pac.window, pac.cred.flo, NULL);
      sfRenderWindow_drawText(pac.window, pac.cred.hug, NULL);
      sfRenderWindow_drawText(pac.window, pac.cred.leo, NULL);
      sfRenderWindow_display(pac.window);
    }
  my_deg(pac);
  return ;
}

credit	my_anim_text(credit cred)
{
  sfText_setPosition(cred.flo, cred.fpos);
  sfText_setPosition(cred.gui, cred.gpos);
  sfText_setPosition(cred.hug, cred.hpos);
  sfText_setPosition(cred.leo, cred.lpos);
  sfText_setScale(cred.flo, placepos(cred.L, cred.l));
  sfText_setScale(cred.leo, placepos(cred.L, cred.l));
  sfText_setScale(cred.gui, placepos(cred.L, cred.l));
  sfText_setScale(cred.hug, placepos(cred.L, cred.l));
  cred.L = cred.L - 0.0001;
  cred.l = cred.l - 0.0001;
  cred.fpos.y = cred.fpos.y - 2;
  cred.gpos.y = cred.gpos.y - 2;
  cred.lpos.y = cred.lpos.y - 2;
  cred.hpos.y = cred.hpos.y - 2;
  return (cred);
}
