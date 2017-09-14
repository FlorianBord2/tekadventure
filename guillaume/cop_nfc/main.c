/*
** main.c for main.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/cop_nfc
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Mon May  1 11:50:55 2017 Guillaume Barthe
** Last update Sat May 27 15:43:52 2017 Guillaume Barthe
*/

#include "../../all.h"

int		hit_nfc(t_my_all *s_all)
{
  sfVector2i	m_pos;
  sfColor	color_pos;

  m_pos = sfMouse_getPosition(NULL);
  if (m_pos.x > 1300 && m_pos.y > 320)
    {
      color_pos = sfImage_getPixel(s_all->salle->img_rond, \
				   m_pos.x - 1300, m_pos.y - 320);
      if (color_pos.r == 31 && color_pos.g == 74 && color_pos.b == 111)
        return (3);
    }
  return (1);
}

int		hit_lecteur(t_my_all *s_all, sfRenderWindow* window, float teille)
{
  static float	rotation = 0;
  static float	count = 0;
  sfVector2f	ori;
  sfText*	txt;

  ori.x = 100;
  ori.y = 100;
  txt = sfText_create();
  sfText_setString(txt, nb_to_char(count));
  sfText_setFont(txt, s_all->salle_txt->font);
  sfText_setCharacterSize(txt, 30);
  sfText_setColor(txt, sfColor_fromRGB(0, 255, 0));
  WRtexte(txt, _WIDTH/2, _HEIGHT/2, window);
  if (hit_nfc(s_all) == 3)
    {
      if (teille > 440 && teille < 500)
	count = 0;
      sfSprite_setOrigin(s_all->salle->cycle, ori);
      sfSprite_setRotation(s_all->salle->cycle, rotation);
      sfRenderWindow_drawSprite(s_all->ati->window, s_all->salle->cycle, NULL);
      rotation = rotation + 0.5;
      if ((count = count + 0.007) >= 100)
	return (2);
    }
  return (1);
}

int		disp_salle(t_my_all *s_all, sfRenderWindow *window)
{
  sfVector2f	ori;
  sfVector2i	m_pos;
  float		count;

  m_pos = m_pos = sfMouse_getPosition(NULL);
  ori.x = 100;
  ori.y = 100;
  s_all->ati->window = window;
  s_all->ati->scale_x = 0.2;
  s_all->ati->scale_y = 0.2;
  count = bouteille_depla(s_all);
  s_all->ati->scale_x = 1;
  s_all->ati->scale_y = 1;
  WRSprite(s_all->salle->porte_o, 0, 200, s_all->ati);
  WRSprite(s_all->salle->rond, 1300, 320, s_all->ati);
  sfSprite_setOrigin(s_all->salle->my_card, ori);
  s_all->ati->scale_x = 0.3;
  s_all->ati->scale_y = 0.3;
  WRSprite(s_all->salle->my_pc, _WIDTH/2 - 276, _HEIGHT/2 - 171, s_all->ati);
  sfSprite_setOrigin(s_all->salle->cycle, ori);
  WRSprite(s_all->salle->cycle, 960, 470, s_all->ati);
  if (hit_lecteur(s_all, window, count) == 2)
    return (2);
  WRSprite(s_all->salle->my_card, m_pos.x, m_pos.y, s_all->ati);
  return (0);
}

int	main_nfc(sfRenderWindow *window, t_my_all *s_all)
{
  int	i;
  int	count;

  i = 0;
  sfRenderWindow_setFramerateLimit(window, 0);
  sfMusic_play(s_all->salle->fort_sound);
  sfMusic_setVolume(s_all->salle->fort_sound, s_all->vol);
  while (sfRenderWindow_isOpen(window))
    {
      if (i == 0)
	{
	  box_err(window, s_all, s_all->salle_txt->my_intro);
	  sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	  i = 1;
	}
      sfRenderWindow_clear(window, sfWhite);
      if ((count = disp_salle(s_all, window)) != 0)
	{
	  sfRenderWindow_setMouseCursorVisible(window, sfTrue);
	  sfRenderWindow_setFramerateLimit(window, 60);
	  return (count);
	}
      sfRenderWindow_display(window);
    }
  return (0);
}
