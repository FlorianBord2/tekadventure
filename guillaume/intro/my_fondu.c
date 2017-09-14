/*
** my_fondu.c for my_fondu.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/intro
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Sat May 27 16:03:02 2017 Guillaume Barthe
** Last update Sat May 27 16:03:30 2017 Guillaume Barthe
*/

#include "../../all.h"

int             fondu(t_my_intro *intro, sfRenderWindow *window)
{
  static int    a = 0;
  sfVector2f position = {0, 0};

  sfSprite_setColor(intro->fondu, sfColor_fromRGBA(0, 0, 0, a));
  sfSprite_setPosition(intro->fondu, position);
  sfRenderWindow_drawSprite(window, intro->fondu, NULL);
  if (a < 255)
    a = a + 10;
  if (a > 255)
    return (2);
  return (0);
}

int     o_part(sfRenderWindow *window, t_my_intro *intro)
{
  if (fondu(intro, window) == 2)
    {
      sfRenderWindow_setFramerateLimit(window, 10);
      last_tap(intro, window);
      return (1);
    }
  return (0);
}
