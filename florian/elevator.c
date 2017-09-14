/*
** elevator.c for  in /home/Neo/Graphical/tekadventure/florian
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Mon May 15 11:32:07 2017 Florian BORD
** Last update Sun May 28 18:12:36 2017 Florian BORD
*/

#include "my.h"

la_struct	in_elevator(la_struct pac)
{
  int	i;

  i = pac.elev.door1_pos.x;
  while (pac.elev.door1_pos.x > i - 200 )
    {
      elevator_disp(pac);
      sfSprite_setPosition(pac.elev.door1, pac.elev.door1_pos);
      sfSprite_setPosition(pac.elev.door2, pac.elev.door2_pos);
      pac.elev.door1_pos.x = pac.elev.door1_pos.x - 1;
      pac.elev.door2_pos.x = pac.elev.door2_pos.x + 1;
    }
  i = 600;
  while (i > 500)
    {
      pac.cor.perso = anim_file_cor(pac.cor.perso, 144, pac);
      sfSprite_setPosition(pac.cor.perso, placepos(800, i));
      elevator_disp(pac);
      i = i - 0.1;
    }
  return (pac);
}

void	elevator_disp(la_struct pac)
{
  sfRenderWindow_clear(pac.window, sfBlack);
  sfRenderWindow_drawSprite(pac.window, pac.cor.parallax, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.cor.back, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.cor.noir, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.elev.door1, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.elev.door2, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.cor.perso, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.cor.Dr, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.cor.Ga, NULL);
  sfRenderWindow_drawSprite(pac.window, pac.cor.door3, NULL);
  sfRenderWindow_display(pac.window);
}
