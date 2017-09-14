/*
** my_sleep.c for my_sleep.c in /home/Ordrix0/GRAPH/tekadventure/guillaume
** 
** Made by Guillaume Barthe
** Login   <Ordrix0@epitech.net>
** 
** Started on  Mon May 22 14:43:29 2017 Guillaume Barthe
** Last update Mon May 22 14:47:10 2017 Guillaume Barthe
*/

#include "../all.h"

void		my_sleep(int delay)
{
  time_t	my_t;
  int		t;

  my_t = time(NULL);
  t = time(NULL);
  while (my_t < t + delay)
    my_t = time(NULL);
}
