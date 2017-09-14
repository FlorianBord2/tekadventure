/*
** main.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Wed Apr 12 13:27:11 2017 Florian BORD
** Last update Sat May 27 17:21:04 2017 Guillaume Barthe
*/

#include "../all.h"

void	my_destroy(la_struct pac)
{
  sfMusic_destroy(pac.mu_menu);
  sfMusic_destroy(pac.gm.daru);
  sfMusic_destroy(pac.sound.menu);
  sfMusic_destroy(pac.sound.gmover);
  sfMusic_destroy(pac.sound.corridor);
  sfMusic_destroy(pac.sound.walk);
  sfFont_destroy(pac.cred.ttf);
  sfRenderWindow_destroy(pac.window);
}

la_struct	my_param2(la_struct pac, sfEvent event)
{
  sfVector2f	posc;
  sfVector2f	scale;

  scale = placepos(pac.stparam.vol / 50, 1);
  if (event.type == sfEvtMouseButtonPressed && pac.last == 1)
    pac = my_param3(pac, event, posc);
  else if (event.type != sfEvtMouseButtonPressed)
    pac.last = 1;
  sfSprite_setRotation(pac.planet, pac.degre);
  pac.degre = pac.degre + 0.005;
  sfSprite_setScale(pac.stparam.volume, scale);
  sfRenderWindow_drawSprite(pac.window, pac.stparam.volume, NULL);
  return (pac);
}

la_struct	my_param(la_struct pac)
{
  sfEvent	event;
  sfVector2f	pos;

  pac.res = 0;
  while (pac.res != 1)
    {
      sfRenderWindow_clear(pac.window, sfWhite);
      sfRenderWindow_drawSprite(pac.window, pac.planet, NULL);
      sfRenderWindow_pollEvent(pac.window, &event);
      pos = placepos(event.mouseMove.x, event.mouseMove.y);
      if (pos.x < 810 && pos.x > 710 && pos.y < 800 && pos.y > 700)
	sfRenderWindow_drawSprite(pac.window, pac.stparam.moins2, NULL);
      else
	sfRenderWindow_drawSprite(pac.window, pac.stparam.moins, NULL);
      if (pos.x < 1210 && pos.x > 1110 && pos.y < 800 && pos.y > 700)
	sfRenderWindow_drawSprite(pac.window, pac.stparam.plus2, NULL);
      else
	sfRenderWindow_drawSprite(pac.window, pac.stparam.plus, NULL);
      pac = my_param2(pac, event);
      pac.res = find_mouse_quit_p(pac, event);
      sfRenderWindow_display(pac.window);
      sfMusic_setVolume(pac.mu_menu, pac.stparam.vol);
      sfMusic_setVolume(pac.sound.menu, pac.stparam.vol);
    }
  sfMusic_play(pac.sound.menu);
  pac.res = 0;
  return (pac);
}

int	menu(la_struct pac)
{
  sfEvent	event;

  pac.res = 0;
  while (pac.res == 0)
    {
      sfRenderWindow_clear(pac.window, sfWhite);
      sfSprite_setRotation(pac.planet, pac.degre);
      sfRenderWindow_pollEvent(pac.window, &event);
      sfRenderWindow_drawSprite(pac.window, pac.planet, NULL);
      if (find_mouse_jouer(pac, event) == 1)
	pac.res = 1;
      if (find_mouse_param(pac, event) == 1)
	pac.res = 2;
      if (find_mouse_credit(pac, event) == 1)
	pac.res = 3;
      if (find_mouse_quit(pac, event) == 1)
	pac.res = 4;
      if (pac.res != 0)
	sfMusic_play(pac.sound.menu);
      sfRenderWindow_display(pac.window);
      pac.degre = pac.degre + 0.05;
    }
  return (pac.res);
}
