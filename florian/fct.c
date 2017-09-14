
/*
** fct.c for  in /home/Neo/zest/menu
** 
** Made by Florian BORD
** Login   <Neo@epitech.net>
** 
** Started on  Wed Apr 26 11:59:32 2017 Florian BORD
** Last update Fri May 26 12:39:32 2017 Florian BORD
*/

#include "../all.h"

sfVector2f      placepos(float x, float y)
{
  sfVector2f    pos;

  pos.x = x;
  pos.y = y;
  return (pos);
}

sfSprite        *load_texture(char *str)
{
  sfTexture     *texture;
  sfSprite      *sprite_flame;

  sprite_flame = sfSprite_create();
  texture = sfTexture_createFromFile(str, NULL);
  sfSprite_setTexture(sprite_flame, texture, sfTrue);
  return (sprite_flame);
}

la_struct	gain_hub(la_struct pac, t_my_all *s_all)
{
  if (pac.cor.door_find == 1)
    {
      sfMusic_stop(pac.sound.walk);
      sfRenderWindow_setFramerateLimit(pac.window, 0);
      while (s_all->elem->code_un != 1 && pac.cor.hub_find == 1)
	{
	  sfRenderWindow_clear(pac.window, sfWhite);
	  if (move_pers(s_all, pac.window) == 0)
	    pac.cor.hub_find = 2;
	  if (s_all->elem->code_un == 1)
	    pac.cor.hubdone = 1;
	  sfRenderWindow_display(pac.window);
	}
      pac.cor.door_find = 0;
      sfRenderWindow_setFramerateLimit(pac.window, 60);
    }
  return (pac);
}

la_struct	my_param3(la_struct pac, sfEvent event, sfVector2f posc)
{
  posc = placepos(event.mouseButton.x, event.mouseButton.y);
  if (posc.x > 710 && posc.x < 810 && posc.y > 700 && posc.y < 800)
    if (pac.stparam.vol > 5)
      {
	sfMusic_play(pac.sound.menu);
	pac.stparam.vol = pac.stparam.vol - 5;
      }
  if (posc.x > 1110 && posc.x < 1210 && posc.y > 700 && posc.y < 800)
    if (pac.stparam.vol < 105)
      {
	sfMusic_play(pac.sound.menu);
	pac.stparam.vol = pac.stparam.vol + 5;
      }
  pac.last = 0;
  return (pac);
}
