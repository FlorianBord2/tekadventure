/*
** main.c for main.c in /home/Ordrix0/GRAPH/tekadventure/guillaume/cop_nfc
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Mon May  1 11:50:55 2017 Guillaume Barthe
** Last update Sat May 27 16:11:28 2017 Guillaume Barthe
*/

#include "../../all.h"

void	transition(t_my_zon *s_zon, sfRenderWindow* window, t_all_zon *i)
{
  s_zon->pos->pos_spawn = i->pos_spawn;
  s_zon->pos->x_zon = i->x_zon;
  s_zon->spawn = i->spawn;
  if ((s_zon->hit = i->hit) >= 150)
    i->zon = 3;
  s_zon->direction = i->direction;
  if ((i->zon = set_zombie(s_zon, window, i->zon)) == 4)
    s_zon->hit = 0;
}

void	value_rt(t_my_zon *s_zon, t_all_zon *i)
{
  i->pos_spawn = s_zon->pos->pos_spawn;
  i->spawn = s_zon->spawn;
  i->hit = s_zon->hit;
  i->x_zon = s_zon->pos->x_zon;
  i->direction = s_zon->direction;
}

void		my_loop(t_my_zon *s_zon, sfRenderWindow* window, t_all_zon *i)
{
  t_all_zon	*i_back;

  i_back = malloc(sizeof (t_all_zon));
  i_back = i;
  walk_perso(s_zon, window);
  while (i_back != NULL)
    {
      transition(s_zon, window, i_back);
      if (sfKeyboard_isKeyPressed(sfKeyE))
	{
	  draw_epee_h(s_zon, window);
	  s_zon->epee_count = s_zon->epee_count + 1;
	}
      else
	{
	  draw_epee_n(s_zon, window);
	  s_zon->epee_count = 0;
	}
      my_life(s_zon, window);
      value_rt(s_zon, i_back);
      i_back = i_back->next;
    }
}

int	z_attack(t_my_zon *s_zon, sfRenderWindow* window, t_all_zon *i)
{
  int	wave;

  wave = 0;
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfWhite);
      if (s_zon->life <= 0)
	{
	  sfMusic_stop(s_zon->ruit);
	  return (0);
	}
      if (s_zon->nb_zon == 0)
	{
	  s_zon->nb_zon = wave;
	  i = my_list(i, wave);
	  wave++;
	}
      set_font(window, s_zon);
      my_loop(s_zon, window, i);
      sfRenderWindow_display(window);
    }
  return (0);
}

int                     main_d_zon(sfRenderWindow *window, t_my_all *s_all, \
				   la_struct pac)
{
  t_my_zon		*s_zon;
  t_all_zon		*i;
  t_data		*data;

  if ((data = main_liste_conf()) == NULL ||\
      (!(s_zon = malloc(sizeof (t_my_zon)))) ||\
      (!(i = malloc(sizeof (t_all_zon)))))
    return (84);
  srand(time(NULL));
  i = NULL;
  my_zon(s_zon, data);
  i = my_list(i, 3);
  box_err(window, s_all, s_zon->instruc);
  sfMusic_play(s_zon->ruit);
  sfMusic_setVolume(s_zon->ruit, s_all->vol);
  z_attack(s_zon, window, i);
  sfMusic_destroy(s_zon->ruit);
  my_deg(pac);
  sfRenderWindow_clear(window, sfWhite);
  WRSprite_window(s_all->my_last, 0, 0, window);
  sfRenderWindow_display(window);
  my_sleep(8);
  my_deg(pac);
  my_credit(pac);
  return (0);
}
