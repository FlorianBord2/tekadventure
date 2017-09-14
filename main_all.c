/*
** main_all.c for main_all.c in /home/Ordrix0/GRAPH/tekadventure
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Thu May  4 17:30:08 2017 Guillaume Barthe
** Last update Sat May 27 17:02:38 2017 Guillaume Barthe
*/

#include "all.h"

int		main()
{
  t_my_tek*	tek;
  t_data	*data;

  if ((data = main_liste_conf()) == NULL)
    return (84);
  if (!(tek = malloc(sizeof (t_my_tek))) ||		\
      (!(tek->s_all = malloc(sizeof (t_my_all)))))
    return (84);
  tek->pac = init_texture(tek->pac, data);
  main_intro(tek->pac.window);
  if (remp(tek->s_all, data) == 84 ||		\
      my_salle(tek->s_all, data) == 84)
    return (84);
  sfMusic_play(tek->pac.mu_menu);
  sfMusic_setVolume(tek->pac.mu_menu, tek->pac.stparam.vol);
  while (sfRenderWindow_isOpen(tek->pac.window))
    {
      tek->pac.res = menu(tek->pac);
      if (hit_menu(tek) == 0)
	return (0);
    }
}
