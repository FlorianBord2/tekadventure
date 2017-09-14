/*
** get_name.c for Tekadventure in /home/Poulard/delivery/tekadventure/Léo
** 
** Made by Léo Pechin
** Login   <Poulard@epitech.net>
** 
** Started on  Tue May 23 15:39:20 2017 Léo Pechin
** Last update Sat May 27 16:46:58 2017 Guillaume Barthe
*/
#include "Tek.h"

char*	get_name(char *name, t_data *d)
{
  while (d != NULL)
    {
      if (check_it(name, d->name) == 1)
	return (d->src);
      d = d->suv;
    }
  return ("./img/error.jpeg");
}

int	count_l(t_data *d)
{
  int	i;

  i = 0;
  while (d != NULL)
    {
      d = d->suv;
      i = i + 1;
    }
  return (i);
}

int	check_it(char *name, char *av)
{
  int	i;

  i = 0;
  while (name[i] == av[i] && (name[i] != '\0'
			      && av[i] != '\0'))
    i = i + 1;
  if (name[i] == '\0' && av[i] == '\0')
    return (1);
  return (0);
}


  
