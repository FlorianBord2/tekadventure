/*
** main.c for main.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/cop_nfc
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Mon May  1 11:50:55 2017 Guillaume Barthe
** Last update Sat May 27 16:49:25 2017 Guillaume Barthe
*/

#include "../../all.h"

void     remp_pos(sfVector2f pos[12])
{
  pos[0].x = 32 * 9;
  pos[0].y = 38;
  pos[1].x = 32 * 4;
  pos[1].y = 0;
  pos[2].x = 0;
  pos[2].y = 38;
  pos[3].x = 0;
  pos[3].y = 0;
  pos[4].x = 32 * 3;
  pos[4].y = 0;
  pos[5].x = 32;
  pos[5].y = 38 * 2;
  pos[6].x = 32 * 4;
  pos[6].y = 0;
  pos[7].x = 32 * 3;
  pos[7].y = 38;
  pos[8].x = 32 * 9;
  pos[8].y = 38;
  pos[9].x = 0;
  pos[9].y = 38 * 2;
  pos[10].x = 32 * 7;
  pos[10].y = 38;
  pos[11].x = 32 * 4;
  pos[11].y = 0;
}


void		entire(t_my_intro *intro, sfRenderWindow* window)
{
  sfVector2f	pos[12];
  int		i;
  int		depla;
  sfVector2f	taille = {32, 38};
  sfVector2f	scale = {3, 3};

  i = 0;
  depla = _WIDTH/2  - 580;
  remp_pos(pos);
  sfRenderWindow_clear(window, sfBlack);
  sfRenderWindow_display(window);
  while (i <= 11)
    {
      WRLetter(pos[i], taille, intro->letter);
      sfSprite_setScale(intro->letter, scale);
      WRSprite_window(intro->letter, depla, 300, window);
      depla = depla + 100;
      i = i + 1;
    }
  sfRenderWindow_display(window);
  my_sleep(3);
}

void		last_tap(t_my_intro *intro, sfRenderWindow* window)
{
  sfVector2f    pos[12];
  int           i;
  int           depla;
  sfVector2f	taille = {32, 38};
  sfVector2f	scale = {3, 3};

  i = 0;
  depla = _WIDTH/2  - 580;
  remp_pos(pos);
  sfRenderWindow_clear(window, sfBlack);
  sfRenderWindow_display(window);
  while (i <= 11)
    {
      sfRenderWindow_clear(window, sfBlack);
      WRLetter(pos[i], taille, intro->letter);
      sfSprite_setScale(intro->letter, scale);
      WRSprite_window(intro->letter, depla, 300, window);
      depla = depla + 50;
      i = i + 1;
      sfRenderWindow_display(window);
    }
  entire(intro, window);
}

int		intro(t_my_intro *intro, sfRenderWindow *window, int vitesse)
{
  sfIntRect	rect;
  sfVector2f	pos[11];
  int		i;
  int		depla;

  i = 0;
  depla = _WIDTH/2 - 350;
  remp_pos(pos);
  while (i <= 11)
    {
      rect.left = pos[i].x;
      rect.top = pos[i].y;
      rect.width = 32;
      rect.height = 38;
      sfSprite_setTextureRect(intro->letter, rect);
      WRSprite_window(intro->letter, depla, rand()%1080, window);
      depla = depla + 50;
      i = i + 1;
    }
  if (vitesse >= 70000)
    if (o_part(window, intro) == 1)
      return (1);
  return (vitesse);
}

int                     main_intro(sfRenderWindow *window)
{
  t_my_intro		*s_intro;
  int			vitesse;

  if (!(s_intro = malloc(sizeof (t_my_intro))))
    return (84);
  sfRenderWindow_setFramerateLimit(window, 60);
  intro_remp(s_intro);
  while (1)
    {
      if ((vitesse % 5000) == 0)
	{
	  sfRenderWindow_clear(window, sfBlack);
	  if (intro(s_intro, window, vitesse) == 1)
	    {
	      sfRenderWindow_setFramerateLimit(window, 60);
	      return (0);
	    }
	}
      vitesse = vitesse + 3000;
      sfRenderWindow_display(window);
    }
}
