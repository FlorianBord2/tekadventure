/*
** find_mouse.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Wed Apr 12 15:54:20 2017 Florian BORD
** Last update Thu May  4 15:25:39 2017 Guillaume Barthe
*/

#include "../all.h"

int	find_mouse_jouer(la_struct pac, sfEvent event)
{
  sfVector2f    LL;
  sfVector2f	pos;
  sfVector2f	posc;

  sfRenderWindow_pollEvent(pac.window, &event);
  LL = placepos((LARG / 2 - 200), (LARG / 2 + 200));
  pos = placepos(event.mouseMove.x, event.mouseMove.y);
  if (event.type == sfEvtMouseButtonPressed)
    {
      posc = placepos(event.mouseButton.x, event.mouseButton.y);
      if (posc.x > LL.x && posc.x < LL.y && posc.y > 100 && posc.y < 200)
	return (1);
    }
  if (pos.y > 100 && pos.y < 200 && pos.x > LL.x && pos.x < LL.y)
    {
      sfRenderWindow_drawSprite(pac.window, pac.jouer2, NULL);
    }
  else
    sfRenderWindow_drawSprite(pac.window, pac.jouer, NULL);
  return (0);
}

int     find_mouse_param(la_struct pac, sfEvent event)
{
  sfVector2f    LL;
  sfVector2f    pos;
  sfVector2f    posc;

  sfRenderWindow_pollEvent(pac.window, &event);
  LL = placepos((LARG / 2 - 200), (LARG / 2 + 200));
  pos = placepos(event.mouseMove.x, event.mouseMove.y);
  if (event.type == sfEvtMouseButtonPressed)
    {
      posc = placepos(event.mouseButton.x, event.mouseButton.y);
      if (posc.x > LL.x && posc.x < LL.y && posc.y > 250 && posc.y < 350)
	return (1);
    }
  if (pos.y > 250 && pos.y < 350 && pos.x > LL.x && pos.x < LL.y)
    {
      sfRenderWindow_drawSprite(pac.window, pac.param2, NULL);
    }
  else
    sfRenderWindow_drawSprite(pac.window, pac.param, NULL);
  return (0);
}

int     find_mouse_credit(la_struct pac, sfEvent event)
{
  sfVector2f    LL;
  sfVector2f    pos;
  sfVector2f    posc;

  sfRenderWindow_pollEvent(pac.window, &event);
  LL = placepos((LARG / 2 - 200), (LARG / 2 + 200));
  pos = placepos(event.mouseMove.x, event.mouseMove.y);
  if (event.type == sfEvtMouseButtonPressed)
    {
      posc = placepos(event.mouseButton.x, event.mouseButton.y);
      if (posc.x > LL.x && posc.x < LL.y && posc.y > 400 && posc.y < 500)
	return (1);
    }
  if (pos.y > 400 && pos.y < 500 && pos.x > LL.x && pos.x < LL.y)
    {
      sfRenderWindow_drawSprite(pac.window, pac.credit2, NULL);
    }
  else
    sfRenderWindow_drawSprite(pac.window, pac.credit, NULL);
  return (0);
}

int     find_mouse_quit(la_struct pac, sfEvent event)
{
  sfVector2f    LL;
  sfVector2f    pos;
  sfVector2f    posc;
  int		sec;

  sec = 0;
  sfRenderWindow_pollEvent(pac.window, &event);
  LL = placepos((LARG / 2 - 200), (LARG / 2 + 200));
  pos = placepos(event.mouseMove.x, event.mouseMove.y);
  sfSprite_setPosition(pac.quit2, placepos(LL.x, 550));
  sfSprite_setPosition(pac.quit, placepos(LL.x, 550));
  if (event.type == sfEvtMouseButtonPressed)
    {
      posc = placepos(event.mouseButton.x, event.mouseButton.y);
      if (posc.x > LL.x && posc.x < LL.y && posc.y > 550 && posc.y < 650)
	return (1);
    }
  if (pos.y > 550 && pos.y < 650 && pos.x > LL.x && pos.x < LL.y)
      sfRenderWindow_drawSprite(pac.window, pac.quit2, NULL);
  else
    sfRenderWindow_drawSprite(pac.window, pac.quit, NULL);
  return (0);
}

int     find_mouse_quit_p(la_struct pac, sfEvent event)
{
  sfVector2f    LL;
  sfVector2f    pos;
  sfVector2f    posc;
  int           sec;

  sec = 0;
  sfRenderWindow_pollEvent(pac.window, &event);
  LL = placepos((LARG / 2 - 200), (LARG / 2 + 200));
  pos = placepos(event.mouseMove.x, event.mouseMove.y);
  if (event.type == sfEvtMouseButtonPressed)
    {
      posc = placepos(event.mouseButton.x, event.mouseButton.y);
      if (posc.x > LL.x && posc.x < LL.y && posc.y > 850 && posc.y < 950)
	return (1);
    }
  sfSprite_setPosition(pac.quit2, placepos(LL.x, 850));
  sfSprite_setPosition(pac.quit, placepos(LL.x, 850));
  if (pos.y > 850 && pos.y < 950 && pos.x > LL.x && pos.x < LL.y)
    sfRenderWindow_drawSprite(pac.window, pac.quit2, NULL);
  else
    sfRenderWindow_drawSprite(pac.window, pac.quit, NULL);
  return (0);
}
