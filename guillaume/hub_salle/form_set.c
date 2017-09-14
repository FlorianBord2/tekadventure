/*
** form_set.c for form_set.c in /home/Ordrix0/techadventure/hub_salle
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Mon Apr 24 17:47:48 2017 Guillaume Barthe
** Last update Thu May  4 15:32:11 2017 Guillaume Barthe
*/

#include "../../all.h"

sfImage*	img(char *path)
{
  sfImage*	img;

  img = sfImage_createFromFile(path);
  return (img);
}

sfText*		LdTxt(char *str, char *t_font)
{
  sfText*	txt;
  sfFont*	font;

  txt = sfText_create();
  sfText_setString(txt, str);
  font = sfFont_createFromFile(t_font);
  sfText_setFont(txt, font);
  sfText_setCharacterSize(txt, 30);
  return (txt);
}

void		WRtexte(sfText* txt, int x, int y, sfRenderWindow* window)
{
  sfVector2f	position;

  position.x = x;
  position.y = y;
  sfText_setPosition(txt, position);
  sfRenderWindow_drawText(window, txt, NULL);
}

void			WRRectangle(sfVector2f pos, sfVector2f len, sfRenderWindow* window, \
				    sfColor color)
{
  sfRectangleShape*	rect;

  rect = sfRectangleShape_create();
  sfRectangleShape_setSize(rect, len);
  sfRectangleShape_setPosition(rect, pos);
  sfRectangleShape_setFillColor(rect, color);
  sfRenderWindow_drawRectangleShape(window, rect, NULL);
}
