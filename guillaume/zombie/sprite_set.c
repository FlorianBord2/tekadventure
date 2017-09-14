/*
** sprite_set.c for sprite_set.c in /home/Ordrix0/scroller
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Sat Apr  1 14:08:48 2017 Guillaume Barthe
** Last update Sat May 27 16:13:09 2017 Guillaume Barthe
*/

#include "../../all.h"

sfSprite*	LdSprite(char* sNom, int repeat)
{
  sfSprite*	sprite;
  sfTexture*	texture;
  sfIntRect	rect;

  rect.left = 0;
  rect.top = 0;
  rect.width = _WIDTH;
  rect.height = _HEIGHT;
  texture = sfTexture_createFromFile(sNom, NULL);
  sprite = sfSprite_create();
  sfSprite_setTexture(sprite, texture, sfTrue);
  if (repeat == 1)
    {
      sfTexture_setRepeated(texture, sfTrue);
      sfSprite_setTextureRect(sprite, rect);
    }
  return (sprite);
}

void		WRSprite(sfSprite* sNom, int x, int y, t_my_ati *ati)
{
  sfVector2f	position;
  sfVector2f	scale;

  position.x = x;
  position.y = y;
  scale.x = ati->scale_x;
  scale.y = ati->scale_y;
  sfSprite_setPosition(sNom, position);
  sfSprite_setScale(sNom, scale);
  if (ati->i == 1)
    sfSprite_setColor(sNom, ati->color);
  sfRenderWindow_drawSprite(ati->window, sNom, NULL);
}

void            WRSprite_window(sfSprite* sNom, int x, \
				int y, sfRenderWindow *window)
{
  sfVector2f    position;

  position.x = x;
  position.y = y;
  sfSprite_setPosition(sNom, position);
  sfRenderWindow_drawSprite(window, sNom, NULL);
}

void    WRLetter(sfVector2f pos, sfVector2f taille, sfSprite *sNom)
{
  sfIntRect     rect;

  rect.left = pos.x;
  rect.top = pos.y;
  rect.width = taille.x;
  rect.height = taille.y;
  sfSprite_setTextureRect(sNom, rect);
}
