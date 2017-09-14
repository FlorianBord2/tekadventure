/*
** sound.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Mon Apr 24 13:30:35 2017 Florian BORD
** Last update Sat May 27 12:26:48 2017 Guillaume Barthe
*/

#include "../all.h"

void		voldown(la_struct pac)
{
  float		vol;

  vol = sfMusic_getVolume(pac.gm.daru);
  while (vol >= 0)
    {
      sfMusic_setVolume(pac.gm.daru, vol);
      vol = vol - 0.001;
    }
}

void		my_deg(la_struct pac)
{
  sfColor	color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  color.a = 0;
  while (color.a < 180)
    {
      sfSprite_setColor(pac.gm.flou, color);
      sfRenderWindow_drawSprite(pac.window, pac.gm.flou, NULL);
      color.a = color.a + 2;
      sfRenderWindow_display(pac.window);
    }
}

void		my_degu(la_struct pac)
{
  sfColor       color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  color.a = 180;
  while (color.a > 0)
    {
      sfRenderWindow_clear(pac.window, sfWhite);
      sfRenderWindow_drawSprite(pac.window, pac.gm.back, NULL);
      sfRenderWindow_drawSprite(pac.window, pac.gm.back2, NULL);
      sfRenderWindow_drawSprite(pac.window, pac.gm.log, NULL);
      sfSprite_setColor(pac.gm.flou, color);
      sfRenderWindow_drawSprite(pac.window, pac.gm.flou, NULL);
      sfRenderWindow_display(pac.window);
      color.a = color.a - 2;
    }
}

void            my_degu_scene(la_struct pac)
{
  sfColor       color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  color.a = 180;
  while (color.a > 0)
    {
      sfRenderWindow_clear(pac.window, sfWhite);
      sfRenderWindow_drawSprite(pac.window, pac.scene1, NULL);
      sfSprite_setColor(pac.gm.flou, color);
      sfRenderWindow_drawSprite(pac.window, pac.gm.flou, NULL);
      sfRenderWindow_display(pac.window);
      color.a = color.a - 2;
    }
}

void            my_degu_scene2(la_struct pac)
{
  sfColor       color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  color.a = 180;
  while (color.a > 0)
    {
      sfRenderWindow_clear(pac.window, sfWhite);
      sfRenderWindow_drawSprite(pac.window, pac.scene2, NULL);
      sfSprite_setColor(pac.gm.flou, color);
      sfRenderWindow_drawSprite(pac.window, pac.gm.flou, NULL);
      sfRenderWindow_display(pac.window);
      color.a = color.a - 2;
    }
}
