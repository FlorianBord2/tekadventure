/*
** menu_menu.c for menu_menu.c in /home/Ordrix0/GRAPH/tekadventure/florian
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Thu May  4 17:25:45 2017 Guillaume Barthe
** Last update Sat May 27 17:17:45 2017 Guillaume Barthe
*/

#include "../all.h"

int	hit_menu(t_my_tek *tek)
{
  if (tek->pac.res != 0)
    {
      tek->s_all->vol = tek->pac.stparam.vol;
      my_deg(tek->pac);
      if (tek->pac.res == 1)
	tek->pac = gm(tek->pac, tek->s_all);
      else if (tek->pac.res == 2)
	tek->pac = my_param(tek->pac);
      else if (tek->pac.res == 3)
	my_credit(tek->pac);
      else if (tek->pac.res == 4)
	{
	  my_destroy(tek->pac);
	  return (0);
	}
    }
  return (1);
}
