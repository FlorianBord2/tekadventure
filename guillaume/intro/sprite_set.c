/*
** sprite_set.c for sprite_set.c in /home/Ordrix0/scroller
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Sat Apr  1 14:08:48 2017 Guillaume Barthe
** Last update Sat May 27 16:05:36 2017 Guillaume Barthe
*/

#include "../../all.h"

void            WRSprite_window(sfSprite* sNom, int x, \
				int y, sfRenderWindow *window)
{
  sfVector2f    position;

  position.x = x;
  position.y = y;
  sfSprite_setPosition(sNom, position);
  sfRenderWindow_drawSprite(window, sNom, NULL);
}


void	WRLetter(sfVector2f pos, sfVector2f taille, sfSprite *sNom)
{
  sfIntRect     rect;

  rect.left = pos.x;
  rect.top = pos.y;
  rect.width = taille.x;
  rect.height = taille.y;
  sfSprite_setTextureRect(sNom, rect);
}
