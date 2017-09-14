/*
** pars.c for tekadventure in /home/Poulard/delivery/tekadventure/Léo
** 
** Made by Léo Pechin
** Login   <Poulard@epitech.net>
** 
** Started on  Wed May  3 10:47:54 2017 Léo Pechin
** Last update Sat May 27 12:20:19 2017 Guillaume Barthe
*/
#include "Tek.h"

t_data		*init_pars(char *av)
{
  t_data	*data;
  int		i;
  int		k;

  i = 0;
  k = 0;
  if (!(data = malloc(sizeof (t_data))) ||
      !(data->name = malloc(sizeof (char)*100)))
    return (NULL);
  data->src = NULL;
  data->suv = NULL;
  while (av[i] != '\n' && av[i] != '\0')
    {
      if (av[i] < '0' || av[i] > '9')
	return (NULL);
      data->name[k] = av[i];
      i = i + 1;
      k = k + 1;
    }
  pars(av, data, i);
  return (data);
}

int	pars(char *av, t_data *data, int i)
{
  t_data	*suv;

  if (!(suv = malloc(sizeof(t_data))))
    return (-1);
  if (av[i] == '\n')
    i = i + 1;
  else if (av[i] == '\0')
    {
      data->suv = NULL;
      return (1);
    }
  else
    return (-1);
  if (av[i] == '#')
    {
      while (av[i] != '\n' && av[i] != '\0')
	i = i + 1;
      pars(av, data, i);
    }
  else
    {
      stock_src(data, suv, av, i);
    }
}

int	stock_src(t_data *data, t_data *suv, char *av, int i)
{
  if (!(suv->src = malloc(sizeof (char) * len_lin(av, i, 1) + 1)) ||
      !(suv->name = malloc(sizeof (char) * len_lin(av, i, 2) + 1)))
    return (-1);
  i = copy_while(av, suv->src, i, '|');
  i = i + 1;
  i = copy_while(av, suv->name, i, '\n');
  data->suv = suv;
  suv->suv = NULL;
  return (pars(av, suv, i));
}

int	stock_name(t_data *data, t_data *suv, char *av, int i)
{
  if (!(suv->name = malloc(sizeof (char) * len_lin(av, i, 2) + 1)))
    return (-1);
  while (av[i] != '#')
    i = i + 1;
  i = copy_while(av, suv->name, i, '\n');
  data->suv = suv;
  suv->suv = NULL;
  return (pars(av, suv, i));
}

int	len_lin(char *av, int i, int opt)
{
  int	nb;

  nb = 0;
  if (opt == 1)
    while (av[i] != '|' && av[i] != '\0')
      {
	i = i + 1;
	nb = nb + 1;
      }
  else
    {
      while (av[i] != '|' && av[i] != '\0')
	i = i + 1;
      if (av[i] != '\0')
	i = i + 1;
      while (av[i] != '\n' && av[i] != '\0')
	{
	  i = i + 1;
	  nb = nb + 1;
	}
    }
  return (nb);
}
