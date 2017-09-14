/*
** sprite_set.c for sprite_set.c in /home/Ordrix0/scroller
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Sat Apr  1 14:08:48 2017 Guillaume Barthe
** Last update Thu May  4 15:33:00 2017 Guillaume Barthe
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
