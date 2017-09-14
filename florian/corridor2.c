/*
** corridor2.c for  in /home/Neo/Graphical/tekadventure/florian
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Fri May  5 19:41:04 2017 Florian BORD
** Last update Tue May 23 13:43:49 2017 Florian BORD
*/

#include "../all.h"

la_struct	colidoor2(la_struct pac, sfEvent event)
{
  if (pac.cor.door3_pos.x > ((LARG / 2) - 350) &&
      pac.cor.door3_pos.x < ((LARG / 2) + 350))
    if (pac.cor.door3_pos.x > ((LONG / 2) - 350) &&
	pac.cor.door3_pos.x < ((LONG / 2) + 350) &&
	pac.shot.done == 1 && pac.cor.hubdone == 1)
      {
	sfRenderWindow_drawSprite(pac.window, pac.cor.up, NULL);
	if (sfKeyboard_isKeyPressed(sfKeyUp))
	  pac.cor.door_find = 3;
      }
  if (pac.elev.door1_pos.x > ((LARG / 2) - 350) &&
      pac.elev.door1_pos.x < ((LARG / 2) + 350))
    if (pac.elev.door1_pos.x > ((LONG / 2) - 350) &&
	pac.elev.door1_pos.x < ((LONG / 2) + 350) && pac.lvlcledone == 2)
      {
	sfRenderWindow_drawSprite(pac.window, pac.cor.up, NULL);
	if (sfKeyboard_isKeyPressed(sfKeyUp))
	    pac.cor.door_find = 4;
      }
  return (pac);
}
